# Regular Expression Matching

### 題目: [https://leetcode.com/problems/regular-expression-matching/](https://leetcode.com/problems/regular-expression-matching/)


## 詳解 (10.cpp)
這題歸類在 Hard。我不確定我是否是最直觀的解，但我會試著詳細解釋。  

我將字串分別處理：  
s = " " + s;  //右移一位方便計算  
p = " " + p;  //右移一位方便計算  
這是為了使 dp[i][j] 中 i 就是 s 的 0~i，j 就是 p 的 0~j，不需要將他寫成 dp[i+1][j+1]  

動態規劃演算法邏輯：  
dp[i][j] 儲存 s 字串的 0~i 是否能對應 p 字串的 0~j  
接下來會分兩類處理  

1.p[j] 是 a~z 或者是 .  
1. p[j] 是 .  
=> dp[i][j] 取決於不看 i 對應 j 的時候是否是對的  
(dp[i][j] = dp[i-1][j-1])  
2. p[j] 是 a ~ z  
=> 若 s[i] == p[j] 則 dp[i][j] 取決於不看 i 對應 j 的時候是否是對的  
(dp[i][j] = dp[i-1][j-1])  
否則就是 false  

2.p[j] 是 *  
1. `*` 不 match 任何字元  
因為 [某字元]* 為一組，當 * 不 match 任何字元，則 dp[i][j] = dp[i][j-2]  
(j-2 是不看 * 與 * 前的[某字元])  
3. `*` 會 match 字元  
[某字元]* 中的 [某字元] 與 s[i] 相等或者 [某字元] 是 . 時，dp[i][j] 取決於不看 s[i] 的情況下 dp[i-1][j] 是否也是對的  
否則 dp[i][j] = false  

<註> dp[0][j] 要先看 p[j] 是否為 *，如果是的話，代表 * 一定不 match 任何字元，則 dp[0][j] = dp[0][j-2]  
(j-2 是不看 * 與 * 前的[某字元])  

**Time Complexity**:  
O($M \times N$)  

**Space Complexity**:  
O($M \times N$)

**Runtime**:  
0 ms | Beats 100.00%

**Memory**:  
8.56 ms | Beats 76.35%
