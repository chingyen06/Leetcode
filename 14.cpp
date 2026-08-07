/*
Runtime:
0ms
Beats
100.00%

Memory:
11.92MB
Beats
38.70%
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i, j;
        string ans = "";
        char temp;

        for (i=0;i<strs[0].size();i++) {
            temp = strs[0][i];

            // cout << temp << endl;

            for (j=1;j<strs.size();j++) {
                if (i >= strs[j].size()) {
                    // cout << i << " " << j << " " << strs[j][i] << endl;
                    return ans;
                }

                if (strs[j][i] != temp) {
                    return ans;
                }
            }

            ans += temp;
        }
        
        return ans;
    }
};