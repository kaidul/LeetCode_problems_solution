class Solution {
    template<typename T> T toInt(string s) { T n = 0; istringstream sin(s); sin >> n; return n; }
public:
    string decodeString(string s) {
        string decodedStr = "";
        stack<string> Stack;
        for(int i = 0, n = s.length(); i < n; ++i) {
            if(s[i] == '[') {
                
                // string key = "";
                // key += s[i];
                // Stack.push(key);
            }
            else if(isdigit(s[i])) {
                string k = "";
                k += s[i];
                while(i + 1 < n and isdigit(s[i + 1])) {
                    k += s[i + 1];
                    ++i;
                }
                Stack.push(k);
            }
            else if(s[i] == ']') {
                string key = "";
                while(!Stack.empty()) {
                    if(isdigit(Stack.top()[0])) break;
                    key = Stack.top() + key;
                    Stack.pop();
                }
//                assert(Stack.top() == "[");
                // Stack.pop();
                int k = toInt<int>(Stack.top());
                Stack.pop();
                string newKey = "";
                newKey.reserve(key.length() * k);
                while(k--) {
                    newKey += key;
                }
                Stack.push(newKey);
            }
            else {
                string key = "";
                key += s[i];
                while(i + 1 < n and s[i + 1] != ']' and !isdigit(s[i + 1])) {
                    key += s[i + 1];
                    ++i;
                }
                Stack.push(key);
            }
        }
        while(!Stack.empty()) {
            decodedStr = Stack.top() + decodedStr;
            Stack.pop();
        }
        return decodedStr;
    }
};