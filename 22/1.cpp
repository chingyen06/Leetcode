class Solution {
public:
    vector<string> generateParenthesis(int n) {
        generate("", n, n);

        return ans;
    }

    void generate(string s, int left, int right) {
        if (left == 0 && right == 0) {
            ans.push_back(s);
            return;
        }

        if (left > 0) {
            generate(s + "(", left-1, right);
        }

        if (right > left) {
            generate(s + ")", left, right-1);
        }
    }

private:
    vector<string> ans;
};
