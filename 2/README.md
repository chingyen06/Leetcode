# Add Two Numbers

### 題目: [https://leetcode.com/problems/two-sum/](https://leetcode.com/problems/add-two-numbers/)

## 詳解 (1.cpp)
這題題目主要是考驗鏈結串列（Linked List）。  
我先創建一個虛擬的開始節點存放串列 l3（一開始為 0），並建立 temp_l3 作為指針指向串列的結尾節點（一開始會是 0）。  
若 l1 或 l2 或 carry(進位) 還有值沒使用就進入 while 迴圈，利用 sum 儲存該位置的加總，並將 sum 除以 10 的餘數設為下一位的 carry，sum 只保留個位（sum = sum 除以 10），再將 sum 存入新節點並把 temp_l3 指向新的節點。
回傳數值的時候將拋棄一開始創建的虛擬節點 0，其餘作為回傳值。

**Time Complexity**:  
O(n)  

**Space Complexity**:  
O(1)

**Runtime**:  
0 ms | Beats 100.00%

**Memory**:  
77.08 MB | Beats 76.33%
