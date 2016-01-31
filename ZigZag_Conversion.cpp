class Solution {
public:
    string convert(string s, int nRows) {
        if(s.empty()) return s;
        string str[nRows + 1];
        int j = 0, flip = 0, len = s.length();
        while(j < len) {
            flip ^= 1;
            if(flip) {
                for(int i = 0; i < nRows; ++i) {
                    if(j < len) str[i] += s[j++];
                    else break;
                }
            } else {
                for(int i = nRows - 2; i > 0; --i) {
                    if(j < len) str[i] += s[j++];
                    else break;
                }
            }
        }
        string result;
        for(int i = 0; i < nRows; ++i) result += str[i];
        return result;
    }
};