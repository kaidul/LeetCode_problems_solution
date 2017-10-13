class Solution {
    bool isMatchRecur(string const& txt, int p, string const& pattern, int q, vector<vector<bool>>& visited, vector<vector<bool>>& dp) {
        if(p == txt.length() and q == pattern.length()) return true;
        if(q == pattern.length()) return false; 
        if(p >= txt.length()) {
            for(int i = q; i < pattern.length(); ++i) {
                if(pattern[i] != '*') {
                    return false;
                }
            }
            return true;
        }

        if(visited[p][q]) return dp[p][q];
        visited[p][q] = true;
        
        if(pattern[q] == '?') {
            return dp[p][q] = isMatchRecur(txt, p + 1, pattern, q + 1, visited, dp);
        } else if(pattern[q] == '*') {
            for(int i = 0; i <= txt.length() - p; ++i) {
                if(isMatchRecur(txt, p + i, pattern, q + 1, visited, dp)) {
                    return dp[p][q] = true;
                }
            }
            return dp[p][q];
        }
        int i = p, j = q;
        for(; i < txt.length() and j < pattern.length() and pattern[j] != '?' and pattern[j] != '*'; ++i, ++j) {
            if(pattern[j] != txt[i]) {
                return dp[p][q] = false;
            }
        }
        return dp[p][q] = isMatchRecur(txt, i, pattern, j, visited, dp);
    }
    
public:
    bool isMatch(string txt, string pattern) {
        int m = txt.length();
        int n = pattern.length();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        return isMatchRecur(txt, 0, pattern, 0, visited, dp);
    }
};