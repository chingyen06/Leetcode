/*
Runtime:
6ms
Beats
33.54%

Memory:
12.80MB
Beats
18.48%
*/

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> mapp = {{1000,"M"}, {900,"CM"}, {500,"D"}, {400,"CD"}, {100,"C"}, {90,"XC"}, {50, "L"}, {40,"XL"}, {10,"X"}, {9,"IX"}, {5,"V"}, {4,"IV"}, {1, "I"}};
        int i;
        string ans = "";

        for (i=0;i<mapp.size();i++) {
            while (num >= mapp[i].first) {
                ans += mapp[i].second;
                num -= mapp[i].first;
            }
        }

        return ans;
    }
};