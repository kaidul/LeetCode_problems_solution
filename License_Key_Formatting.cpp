class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        vector<char> chars;
        for(int i = 0; i < (int)S.length(); i++) {
            if(isalnum(S[i])) {
                chars.push_back(S[i]);
            }
        }
        int firstLen = (int)chars.size() % K;
        string result = "";
        int i = 0;
        while(i < firstLen) {
            result += toupper(chars[i++]);
        }
        if(!result.empty() and i < (int)chars.size()) {
            result += '-';
        }
        int len = 0;
        while(i < (int)chars.size()) {
            if(len == K) {
                result += '-';
                len = 0;
            }
            result += toupper(chars[i++]);
            len++;
        }
        
        return result;
    }
};