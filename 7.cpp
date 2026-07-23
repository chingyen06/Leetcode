class Solution {
public:
    int reverse(int x) {
        int mod, ans = 0;

        while (x != 0) {
            mod = x % 10;
            x /= 10;

            // +
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && mod > 7)) {
                return 0;
            }

            // -
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && mod < -8)) {
                return 0;
            }

            ans = ans * 10 + mod;
        }

        return ans;
    }
};