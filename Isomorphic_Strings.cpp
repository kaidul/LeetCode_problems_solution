class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hash1, hash2;
        int m = s.length();
        int n = t.length();
        if(m != n) return false;
        for(int i = 0; i < m; ++i) {
            if((hash1[s[i]] and hash1[s[i]] != t[i]) or (hash2[t[i]] and hash2[t[i]] != s[i])) {
                return false;
            }
            hash1[s[i]] = t[i];
            hash2[t[i]] = s[i];
        }
        return true;
    }
};