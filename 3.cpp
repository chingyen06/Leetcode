class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right, Max = 0;
        int a[128]={};

        for (right=0;right<s.size();right++) {
            while (a[s[right]] > 0) {
                a[s[left]] = 0;
                left++;
            }

            a[s[right]] = 1;

            if (right - left + 1 > Max)
                Max = right - left + 1;
        }

        return  Max;
    }
};