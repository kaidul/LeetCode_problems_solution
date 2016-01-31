class Solution {
public:
    void generateParenthesisUtils(string str, int left, int right, int n, vector<string> &res) {
        if (left == n and right == n) {
            res.push_back(str);
            return;
        }
        if (left < n) generateParenthesisUtils(str + "(", left + 1, right, n, res);
        if (left > right) generateParenthesisUtils(str + ")", left, right + 1, n, res);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n == 0) return res;
        generateParenthesisUtils("", 0, 0, n, res);
        return res;
    }
};