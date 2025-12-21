class Solution {
public:
    bool isMatch(string s, string p) {
        s = " " + s;  //右移一位方便計算
        p = " " + p;  //右移一位方便計算

        int i, j;
        bool dp[21][21], temp1, temp2;

        memset(dp, false, sizeof(dp));
        dp[0][0] = true;  // 兩個都是空字串是對的

        for (j=2;j<p.size();j++) {
            if (p[j] == '*') {
                // * 可以把 * 和前面的字元一起消掉，看 j-2
                // (* 不使用的意思)
                dp[0][j] = dp[0][j-2];
            }
        }

        for (i=1;i<s.size();i++) {
            for (j=1;j<p.size();j++) {
                if (p[j] != '*') {  // 先處理英文字母與. (較簡單)
                    if (p[j] == '.') {
                        // 若前面 s 的 0~i-1 與 p 的 0~j-1 是對的
                        // 那麼 s 的 0~i 與 p 的 0~j 也是對的
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else {  // 英文字母
                        if (s[i] != p[j]) {
                            dp[i][j] = false;
                        }
                        else {  // s[i] 與 p[j] 相同
                            // 若前面 s 的 0~i-1 與 p 的 0~j-1 是對的
                            // 那麼 s 的 0~i 與 p 的 0~j 也是對的
                            dp[i][j] = dp[i-1][j-1];
                        }
                    }
                }
                else {
                    // 1. * 不 match 任何字元
                    temp1 = dp[i][j-2];  // [某字元]* 可以當作沒用，所以就看 s 的 0~i 與 p 的 0~j-2 是不是對的
                    
                    // 2. * 會 match 字元
                    if (s[i] == p[j-1] || p[j-1] == '.') {  // [某字元]* 中的 [某字元] 與 s[i] 相等或者 [某字元] 是 .
                        // 看 s 的 0~i-1 與 p 的 0~j 是不是對的
                        // (因為 * 可以同時替代多個字元，所以看上一個是不是也是對的)
                        temp2 = dp[i-1][j];
                    }
                    else {
                        temp2 = false;
                    }

                    // 整理
                    if (temp1 || temp2) {  // 上面兩種可能有至少有一個是對的
                        dp[i][j] = true;  // 這個位置就是對的
                    }
                    else {
                        dp[i][j] = false;
                    }
                }
            }
        }

        // for (i=0;i<s.size();i++) {
        //     for (j=0;j<p.size();j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return dp[s.size()-1][p.size()-1];
    }
};
