class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1);
        int i, j, k, l;

        dp[0] = {""};

        // (A) B
        // ex. n = 3, 其一為 (())() => A = (), B = ()
        for (i=1;i<=n;i++) {  // n = i 時候
            for (j=0;j<i;j++) {  // A 有幾個 ()
                for (k=0;k<dp[j].size();k++) {  // 遍歷 A 的可能
                    for (l=0;l<dp[i-j-1].size();l++) {  // 遍歷 B 的可能 (-1 是因為 A 外面已經包一層括號了)
                        dp[i].push_back("("+dp[j][k]+")"+dp[i-j-1][l]);
                    }
                }
            }
        }

        return dp[n];
    }
};
