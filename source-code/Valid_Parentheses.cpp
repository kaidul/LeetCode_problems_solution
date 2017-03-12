// without extra space
class Solution {
public:
    bool isValid(string s) {
        int first = 0, second = 0, third = 0;
        for(int i = 0; i < (int)s.length(); ++i) {
            if(s[i] == '(') {
                ++first;
            } else if(s[i] == ')') {
                --first;
            }else if(s[i] == '{') {
                ++second;
            } else if(s[i] == '}') {
                --second;
            }else if(s[i] == '[') {
                ++third;
            } else if(s[i] == ']') {
                --third;
            }
            if(first < 0 or second < 0 or third < 0) {
                return false;
            }
        }
        return first == 0 and second == 0 and third == 0;
    }
};

// using stack
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