class Solution {
public:
    int romanToInt(string s) {
        int i, ans = 0;
        unordered_map<char, int> mapp = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};

        for (i=0;i<s.size();i++) {
            if (i > 0 && mapp[s[i]] > mapp[s[i-1]]) {
                ans += mapp[s[i]] - 2 * mapp[s[i-1]];
            }
            else {
                ans += mapp[s[i]];
            }
        }

        return ans;
    }
};