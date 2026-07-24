class Solution {
public:
    int myAtoi(string s) {
        int i, start = 0, ans = 0, sign = 0;

        while (start < s.size() && s[start] == ' ') {
            start++;
        }

        for (i=start;i<s.size();i++) {
            if (sign == 0 && (s[i] == '+' || s[i] == '-')) {
                if (s[i] == '+')
                    sign = 1;
                else
                    sign = -1;
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                // -
                if (sign == -1) {
                    if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && (s[i]-'0') >= 8))
                        return INT_MIN;
                }
                
                // +
                if (sign == 1) {
                    if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && (s[i]-'0') >= 7))
                        return INT_MAX;
                }

                ans = ans * 10 + (s[i]-'0');

                if (sign == 0)
                    sign = 1;

                // cout << ans << " " << s[i] << endl;
            }
            else {
                break;
            }
        }

        if (sign == 0)
            return ans;

        return ans * sign;
    }
};