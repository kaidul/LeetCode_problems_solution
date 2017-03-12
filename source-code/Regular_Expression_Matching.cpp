// using dp.. dp isn't very fast here as range is small
class Solution {
    bool isMatch(string const& s, int i, string const& p, int j, vector<vector<int>>& dp) {
        int m = (int)p.length(), n = (int)s.length();
        if(j == m) {
            return (i == n);
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(j < m - 1 and p[j + 1] == '*') {
            if(isMatch(s, i, p, j + 2, dp)) {
                return dp[i][j] = true;
            }
            while(i < n and (p[j] == '.' or p[j] == s[i])) {
                if(isMatch(s, i + 1, p, j + 2, dp)) {
                    return dp[i][j] = true;
                }
                i++;
            }
        } else {
            if(i == n) {
                return false;
            }
            if(p[j] == '.' or p[j] == s[i]) {
                return dp[i][j] = isMatch(s, i + 1, p, j + 1, dp);    
            }
        }
        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = (int)s.length();
        int m = (int)p.length();
        vector<vector<int>> dp(n + 1, vector<int>(m, -1));
        return isMatch(s, 0, p, 0, dp);
    }
};

// copying substring as function argument(slower) 
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.length() == 0) {
            return s.length() == 0;
        }

        if(p.length() > 1 && p[1] == '*') {
            if(isMatch(s, p.substr(2))) {
                return true;
            }
            int i = 0;
            while(i < s.length() && (p[0] == '.' || p[0] == s[i])) {
                if(isMatch(s.substr(i + 1), p.substr(2))) {
                    return true;
                }
                ++i;
            }
            return false;
        }
        else {
            if(s.length() == 0)
                return false;
            if(p[0] != '.' && p[0] != s[0])
                return false;
            return isMatch(s.substr(1), p.substr(1));
        }
    }
};