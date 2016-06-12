class Solution {
    bool isScramble(string const& s1, string const& s2, int indx1, int indx2, int len, vector<vector<vector<bool>>>& visited, vector<vector<vector<bool>>>& dp) {
        
        if(len == 1) {
            return dp[indx1][indx2][len] = (s1[indx1] == s2[indx2]);
        }
        
        if(visited[indx1][indx2][len]) {
           return dp[indx1][indx2][len]; 
        }
        
        visited[indx1][indx2][len] = true;
        
        for(int i = 1; i < len; ++i) {
            bool sameOrder = isScramble(s1, s2, indx1, indx2, i, visited, dp) and 
                             isScramble(s1, s2, indx1 + i, indx2 + i, len - i, visited, dp);
                             
            if(sameOrder) { return dp[indx1][indx2][len] = true; }
            
            bool swapedOrder = isScramble(s1, s2, indx1, indx2 + len - i, i, visited, dp) and
                               isScramble(s1, s2, indx1 + i, indx2, len - i, visited, dp);
                               
            if(swapedOrder) { return dp[indx1][indx2][len] = true; }
        }
        
        return dp[indx1][indx2][len] = false;
    }
    
public:
    bool isScramble(string s1, string s2) {
        if(s1.empty() and s2.empty()) return true;
        int n1 = (int)s1.length();
        int n2 = (int)s2.length();
        if(n1 != n2) return false;
        
        // recursive
        // vector<vector<vector<bool>>> dp(n1, vector<vector<bool>>(n1, vector<bool>(n1 + 1)));
        // vector<vector<vector<bool>>> visited(n1, vector<vector<bool>>(n1, vector<bool>(n1 + 1, false)));
        
        // return isScramble(s1, s2, 0, 0, n1, visited, dp);
        

        // iterative
        
        vector<vector<vector<bool>>> dp(n1, vector<vector<bool>>(n1, vector<bool>(n1 + 1, false)));
        
        for(int k = 1; k <= n1; ++k) {
            for(int i = 0; i + k <= n1; ++i) {
                for(int j = 0; j + k <= n1; ++j) {
                    if(k == 1) {
                        dp[i][j][k] = (s1[i] == s2[j]);
                    }
                    else {
                        for(int l = 1; l < k and !dp[i][j][k]; ++l) {
                            dp[i][j][k] = (dp[i][j][l] and dp[i + l][j + l][k - l]) or
                                          (dp[i][j + k - l][l] and dp[i + l][j][k - l]);
                        }
                    }
                }
            }
        }
        
        return dp[0][0][n1];
    }
};