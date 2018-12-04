class Solution {
    string wordAfterTyping(string word) {
        stack<char> Stack;
        for(char ch : word) {
            if(ch == '#') {
                if(!Stack.empty()) {
                    Stack.pop();
                }
            } else {
                Stack.push(ch);
            }
        }
        string result = "";
        while(!Stack.empty()) {
            result += Stack.top();
            Stack.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
public:
    bool backspaceCompare(string S, string T) {
        return wordAfterTyping(S) == wordAfterTyping(T);
    }
};