# Two Sum

### 題目: https://leetcode.com/problems/two-sum/
**Follow-up**: Can you come up with an algorithm that is less than O(n^2) time complexity?

## 1. 暴力解 (1.cpp)
直接遍歷每一個可能符合答案的數字組合，找出唯一解。

**Time Complexity**:  
O(n^2)  

**Space Complexity**:  
O(1)  

**Runtime**:  
45 ms | Beats 24.11%

**Memory**:  
14.03 MB | Beats 72.08%


## 2. 哈希表（Hash Table） (2.cpp)
建立一個unordered_map作為哈希表。  
遍歷0 ~ 最後在nums中的數值，並將已搜尋到的值存入哈希表（key為該位置的索引值）。
每一次遍歷都會令target - 該索引值在nums中的數值為complement，並用unordered_map的find找出哈希表中以complement為key的數值（unordered_map[complement]，此處時間複雜度為O(1)）。

**Time Complexity**:  
O(n)  

**Space Complexity**:  
O(n)  

**Runtime**:  
1 ms | Beats 83.67%

**Memory**:  
14.74 MB | Beats 41.11%
