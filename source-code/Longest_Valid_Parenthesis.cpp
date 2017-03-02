class Solution {
public:
    int longestValidParentheses(string s) {
        stack <int> Stack;
        int maxLen = 0;
        int lastPos = -1;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '(') {
                Stack.push(i);
            } else {
                if(Stack.empty()) {
                    lastPos = i;
                } else {
                    Stack.pop();
                    if(Stack.empty()) {
                        maxLen = max(maxLen, i - lastPos);
                    } else {
                        maxLen = max(maxLen, i - Stack.top());
                    }
                }
            }
        }
        return maxLen;
    }
};