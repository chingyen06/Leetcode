class Solution {
public:
    bool isPalindrome(int x) {
        int reverse_x = 0;
        
        if (x < 0  || (x % 10 == 0 && x != 0))
            return false;

        while (reverse_x < x) {  // 一半就夠
            reverse_x = reverse_x * 10 + x % 10;
            x /= 10;
        }

        if (x == reverse_x || x == reverse_x / 10)
            return true;
        return false;
    }
};