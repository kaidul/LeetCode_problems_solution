class Solution {
    inline bool isOperator(char ch) {
        return (ch == '-' or ch == '*' or ch == '+');
    }
    
    int eval(int a, int b, char op) {
        int val;
        if(op == '*') {
            val = a * b;
        } else if(op == '-') {
            val = a - b;
        } else if(op == '+') {
            val = a + b;
        }
        return val;
    }
    
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        if(input.empty()) return result;
        int n = (int)input.length();
        for(int i = 0; i < n; ++i) {
            if(!isOperator(input[i])) {
                continue;
            }
            vector<int> leftValues = diffWaysToCompute(input.substr(0, i));
            vector<int> rightValues = diffWaysToCompute(input.substr(i + 1));
            
            for(int leftVal: leftValues) {
                for(int rightVal: rightValues) {
                    result.push_back(eval(leftVal, rightVal, input[i]));
                }
            }
        }
        
        if(result.empty()) {
           result.push_back(stoi(input)); 
        }
        
        return result;
    }
};