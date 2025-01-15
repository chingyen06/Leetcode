class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i;
        unordered_map<int, int> hash;

        for (i=0;i<nums.size();i++) {
            int complement = target - nums[i];

            if (hash.find(complement) != hash.end())  //如果hash[complement]存在
                return {i, hash[complement]};
            
            hash[nums[i]] = i;  //用hash[nums[i]] = i表示nums[i]這個值在nums中的位置為i
        }

        return {};
    }
};
