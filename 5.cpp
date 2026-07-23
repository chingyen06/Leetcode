class Solution {
public:
    string longestPalindrome(string s) {
        int i, j;
        int left, right, start, len, Max = 0;
        string ans = "";

        for (i=0;i<s.size();i++) {
            for (j=0;j<=1;j++) {
                left = i;
                right = i + j;

                while (left >= 0 && right < s.size()) {
                    if (s[left] != s[right]) {
                        break;
                    }

                    left--;
                    right++;
                }

                if (Max < right - left - 1) {
                    start = left + 1;
                    Max = right - left - 1; // (right-1) + (left+1) - 1
                }
            }
        }

        for (i=0;i<Max;i++) {
            ans += s[start+i];
        }

        return ans;
    }
};