# Longest Palindromic Substring

### 題目: [https://leetcode.com/problems/longest-palindromic-substring/](https://leetcode.com/problems/longest-palindromic-substring/)


## 詳解 (5.cpp)
這題是在考動態規劃，我的方法不是快速解，但是是最直觀的解法。  

我們利用 dp[i][j] 來判斷字串 i ~ j 是不是回文，具體方法如下：  
1. i == j  
=> 一定是回文 (dp[i][j] = true)  
2. j == i + 1  
如果 s[i] == s[j]  
=> 是回文 (dp[i][j] = true)  
3. 其他情況  
如果 s[i] == s[j] 且 **dp[i+1][j-1] == true**  
當 i 跟 j 相同，且 i+1 ~ j-1 是回文的話，那 i ~j 也是回文  
=> 是回文 (dp[i][j] = true)  

最後我們透過 Max[3] = {最大長度, 起點, 終點} 去存最大長度多少  
只要 dp[i][j] 是回文， j - i + 1 都去跟 Max[0] 比較並存大的  
最後輸出 Max[1] ~ Max[2] 的字串就是結果  

**Time Complexity**:  
O($n^2$)  

**Space Complexity**:  
O($n^2$)

**Runtime**:  
103 ms | Beats 29.54%

**Memory**:  
10.43 MB | Beats 56.02%
