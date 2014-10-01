class Solution {
public:
    bool isValid(string s) {
        stack <char> Stack;
        for(int i = 0; i < s.length(); ++i) {
             if(s[i] == '(' or s[i] == '{' or s[i] == '[')
                Stack.push(s[i]);
             else {
                 if(Stack.empty()) return false;
                 if(s[i] == ')') if(Stack.top() != '(') return false;
                 else if(s[i] == '}') if(Stack.top() != '{') return false;
                 else if(s[i] == ']') if(Stack.top() != '[') return false;
                 Stack.pop();
             }     
        }
        return Stack.empty();
    }
};