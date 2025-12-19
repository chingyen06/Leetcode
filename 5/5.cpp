class Solution {
public:
    string longestPalindrome(string s) {
        int i, j, len = s.size();
        string ans = "";
        bool dp[1000][1000];
        int Max[3]={};  // {最大長度, 起點, 終點}

        memset(dp, false, sizeof(dp));

        for (i=len-1;i>=0;i--) {
            for (j=i;j<len;j++) {
                if (i == j) {
                    dp[i][j] = true;
                }
                else if (s[i] == s[j]) {
                    if (j == i + 1) {
                        dp[i][j] = true;
                    }
                    else if (dp[i+1][j-1]) {
                        dp[i][j] = true;
                    }
                }

                if (dp[i][j] && (j - i + 1) > Max[0]) {
                    Max[0] = j - i + 1;
                    Max[1] = i;
                    Max[2] = j;
                }
            }
        }

        for (i=Max[1];i<=Max[2];i++) {
            ans += s[i];
        }

        return ans;
    }
};
