class Solution {
public:
    string convert(string s, int numRows) {
        int i, dir = 1, pos = 0;
        string ans[numRows], total = "";

        for (i=0;i<numRows;i++) {
            ans[i] = "";
        }

        if (numRows == 1)
            return s;

        for (i=0;i<s.size();i++) {
            ans[pos] += s[i];

            if (pos == numRows - 1)
                dir = -1;
            else if (pos == 0)
                dir = 1;

            pos += dir;
        }

        for (i=0;i<numRows;i++) {
            total += ans[i];
        }

        return total;
    }
};