class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = (int)s.length();
        int n = (int)t.length();
        if(m > n) return false;
        int i = 0, k = 0;
        while(i < m and k < n) {
            if(s[i] == t[k]) ++i;
            ++k;
        }
        return i == m;
    }
};