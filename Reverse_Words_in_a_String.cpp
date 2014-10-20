class Solution {
public:
    void reverseWords(string &s) {
        stack <string> words;
        int start;
        string tmp;
        for(int i = 0, n = s.length(); i < n; ++i) {
            start = i;
            while(s[i] and s[i] != ' ') ++i;
            tmp = s.substr(start, i - start);
            if(!tmp.empty()) words.push(tmp);
        }
        s = "";
        string pop;
        while(!words.empty()) {
            pop = words.top();
            words.pop();
            s += pop + " ";
        }
        if(!s.empty()) s.erase(s.length() - 1, 1);
    }
};