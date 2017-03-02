class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int n = str.length();
        for(int len = n / 2; len >= 1; len--) {
            if(n % len != 0) {
                continue;
            }
            int m = n / len;
            string substr = str.substr(0, len);
            int j = 0;
            for(j = 1; j < m and (str.substr(j * len, len) == substr); ++j);
            if(j == m) {
                return true;
            }
        }
        return false;
    }
};