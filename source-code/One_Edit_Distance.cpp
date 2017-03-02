class Solution {
    bool isOneEditDistanceUtil(string const& s, string const& t) {
        int sLen = s.length();
        int tLen = t.length();
        if(tLen > sLen) {
            return isOneEditDistanceUtil(t, s);
        }
        bool flag = false;
        for(int i = 0, k = 0; i < tLen; ++i, ++k) {
            if(t[i] != s[k]) {
                if(flag) {
                    return false;
                }
                k++;
                flag = true;
            }
            if(s[k] != t[i]) {
                return false;
            }
        }
        return true;
    }
public:
    bool isOneEditDistance(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();
        if(sLen == tLen) {
            int different = 0;
            for(int i = 0; i < sLen; ++i) {
                different += (s[i] != t[i]);
            }
            return (different == 1);
        } else if(abs(sLen - tLen) == 1) {
            return isOneEditDistanceUtil(s, t);
        }
        return false;
    }
};