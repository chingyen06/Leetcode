class Solution {
public:
    string convert(string s, int numRows) {
        int i, j;
        string ans[numRows], total = "";

        for (i=0;i<numRows;i++) {
            ans[i] = "";
        }

        if (numRows == 1)
            return s;

        // i = i + (numRows) + (numRows - 2) = i - 2 + numRows * 2
        for (i=0;i<s.size();i=i-2+numRows*2) {
            for (j=0;j<numRows;j++) {
                if (i + j >= s.size())
                    break;
                ans[j] += s[i+j];
            }
            for (j=0;j<numRows-2;j++) {
                if (i + j + numRows >= s.size())
                    break;

                ans[numRows-j-2] += s[i+j+numRows];
            }
        }

        for (i=0;i<numRows;i++) {
            total += ans[i];
        }

        return total;
    }
};