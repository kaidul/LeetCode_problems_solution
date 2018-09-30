class Solution {
public:
    string simplifyPath(string path) {
        string result = "/";
        deque<string> dQ;
        for(int i = 0; i < path.length(); ) {
            int pos = path.find('/', i);
            string dir;
            if(pos == string::npos) {
                pos = path.length();
            }
            dir = path.substr(i, pos - i);
            if(!dir.empty()) {
                if(dir == ".") {
                    // nothing
                } else if(dir == "..") {
                    if(!dQ.empty()) {
                        dQ.pop_back();
                    }
                } else {
                    dQ.push_back(dir);    
                }
            }
            // skip all redundant slaces
            for( ;pos < path.length() and path[pos] == '/'; ++pos);
            
            i = pos;
        }
        while(!dQ.empty()) {
            result += dQ.front();
            dQ.pop_front();
            if(!dQ.empty()) result += '/';
        }
        return result;
    }
};