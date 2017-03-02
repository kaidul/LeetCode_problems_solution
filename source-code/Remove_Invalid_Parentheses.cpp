class Solution {
    void removeInvalidParenthesesUtils(int indx, int left, int right, int leftToRmv, int rightToRmv, int k, string& sol, string& expr, unordered_set<string>& resultSet) {
        
        if(indx >= (int)expr.length()) {
            if(left == right) {
                resultSet.insert(sol);
            }
            return;
        }
        if(expr[indx] != '(' and expr[indx] != ')') {
            if(k < (int)sol.length()) {
                sol[k] = expr[indx];
                removeInvalidParenthesesUtils(indx + 1, left, right, leftToRmv, rightToRmv, k + 1, sol, expr, resultSet);    
            }
            return;
        }
        if(expr[indx] == '(') {
            if(k < (int)sol.length()) {
                sol[k] = expr[indx];
                removeInvalidParenthesesUtils(indx + 1, left + 1, right, leftToRmv, rightToRmv, k + 1, sol, expr, resultSet);
            }
            if(leftToRmv > 0) {
                removeInvalidParenthesesUtils(indx + 1, left, right, leftToRmv - 1, rightToRmv, k, sol, expr, resultSet);
            }
            return;
        }
        if(expr[indx] == ')') {
            if(k < (int)sol.length() and right < left) {
                sol[k] = expr[indx];
                removeInvalidParenthesesUtils(indx + 1, left, right + 1, leftToRmv, rightToRmv, k + 1, sol, expr, resultSet);
            }
            if(rightToRmv > 0) {
                removeInvalidParenthesesUtils(indx + 1, left, right, leftToRmv, rightToRmv - 1, k, sol, expr, resultSet);
            }
        }
        
    }
    
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        if(s.empty()) {
            result.push_back(s);
            return result;
        }
        int n = (int)s.length();
        int left = 0, right = 0;
        int cnt = 0;
        int balanced = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '(') {
                ++left;
                ++cnt;
            } else if(s[i] == ')') {
                ++right;
                if(cnt > 0) {
                    --cnt;
                    ++balanced;
                }
            }
        }
        int leftToRmv = left - balanced;
        int rightToRmv = right - balanced;
        unordered_set<string> resultSet;
        string sol;
        sol.resize((int)s.length() - leftToRmv - rightToRmv);
        removeInvalidParenthesesUtils(0, 0, 0, leftToRmv, rightToRmv, 0, sol, s, resultSet);
        for(auto& val: resultSet) {
            result.push_back(val);
        }
        return result;
    }
};