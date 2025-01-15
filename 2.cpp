class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i;
        unordered_map<int, int> hash;

        for (i=0;i<nums.size();i++) {
            int complement = target - nums[i];

            if (hash.find(complement) != hash.end())  //如果 hash[complement] 存在
                return {i, hash[complement]};
            
            hash[nums[i]] = i;  //用 hash[nums[i]] = i 表示 nums[i] 這個值在 nums 中的位置為 i
        }

        return {};
    }
};
