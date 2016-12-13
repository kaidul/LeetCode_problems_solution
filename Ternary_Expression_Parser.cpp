class Solution {
    int findQuestionMark(int left, string& expr) {
        for(int i = left, k = 0; i < expr.length(); ++i) {
            if(expr[i] == '?') {
                if(k == 0) { return i; }
                --k;
            } else if(expr[i] == ':') {
                ++k;
            }
        }
        return -1;
    }
    
public:
    string parseTernary(string expression) {
        int n = expression.length();
        if(n <= 1) { return expression; }
        stack<string> trueExpr;
        stack<string> falseExpr;
        reverse(expression.begin(), expression.end());
        trueExpr.push(expression);
        
        while(!falseExpr.empty() or !trueExpr.empty()) {
            if(falseExpr.empty()) {
                if(trueExpr.top().length() == 1) {
                    return trueExpr.top();
                }
            }
            if(trueExpr.empty()) {
                if(falseExpr.top().length() == 1) {
                    return falseExpr.top();
                }
            }
            int i = 0;
            expression = trueExpr.empty() ? falseExpr.top() : trueExpr.top();
            if(!trueExpr.empty()) { trueExpr.pop(); } else { falseExpr.pop(); }
            n = expression.length();
            int colonPos = expression.find(':', i);
            if(colonPos != string::npos) {
                string fExpr = expression.substr(i, colonPos - i);
                falseExpr.push(fExpr);
            }
            i = colonPos + 1;
            int quesPos = findQuestionMark(i, expression);
            if(quesPos != string::npos) {
                string tExpr = expression.substr(i, quesPos - i);
                trueExpr.push(tExpr);
            }
            i = quesPos + 1;
            if(expression[i] == 'T') {
                falseExpr.pop();
                string rest = expression.substr(i + 1, n - i - 1);
                string top = trueExpr.top();
                trueExpr.pop();
                trueExpr.push(top + rest);
            } else {
                trueExpr.pop();
                string rest = expression.substr(i + 1, n - i - 1);
                string top = falseExpr.top();
                falseExpr.pop();
                falseExpr.push(top + rest);
            }
            
        }
        
        return "-1";
    }
};