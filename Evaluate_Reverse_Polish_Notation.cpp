class Solution {
public:
    bool isOperator(string token) {
        return token == "+" or token == "-" or token == "*" or token == "/"; 
    }
    int eval(int a, int b, string Operator) {
        int ret;
        if(Operator == "+") return a + b;
        else if(Operator == "-") return a - b;
        else if(Operator == "*") return a * b;
        else return a / b;
        
    }
    int evalRPN(vector<string> &tokens) {
        stack <int> Stack;
        for(int i = 0, n = tokens.size(); i < n; ++i) {
            if(!isOperator(tokens[i])) {
                Stack.push(atoi(tokens[i].c_str()));
            } else {
                int b = Stack.top();
                Stack.pop();
                int a = Stack.top();
                Stack.pop();
                int value = eval(a, b, tokens[i]);
                Stack.push(value);
            }
        }
        int ans = Stack.top();
        return ans;
    }
};