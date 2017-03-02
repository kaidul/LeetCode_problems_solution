class Solution {
public:
    string simplifyPath(string path) {
        string result = "/";
        stack<string> Stack;
        for(int i = 0; i < path.length(); ) {
            int pos = path.find('/', i);
            string dir;
            if(pos == string::npos) {
                dir = path.substr(i, path.length() - i);
            } else {
                dir = path.substr(i, pos - i);    
            }
            if(!dir.empty()) {
                if(dir == ".") {
                    // nothing
                } else if(dir == "..") {
                    if(!Stack.empty()) {
                        Stack.pop();
                    }
                } else {
                    Stack.push(dir);    
                }
            }
            if(pos == string::npos) {
                pos = path.length();
            }
            // skip all redundant slaces
            for( ;pos < path.length() and path[pos] == '/'; ++pos);
            i = pos;
        }
        stack<string> Stack2;
        while(!Stack.empty()) {
            Stack2.push(Stack.top());
            Stack.pop();
        }
        while(!Stack2.empty()) {
            result += Stack2.top();
            Stack2.pop();
            if(!Stack2.empty()) result += '/';
        }
        return result;
    }
};