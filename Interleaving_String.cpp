class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n = s3.length();
        if (n1 + n2 != n) {
            return false;
        }
        if (s1.empty() and s2.empty() and s3.empty()) {
            return true;
        }

        vector<vector<bool> > dp(n1 + 1, vector<bool>(n2 + 1, false));

        // dp[i][j] = true if s3[i + j - 1] can be formed by s1[i - 1] and s2[j - 1]
        dp[0][0] = true;
        for (int i = 1; i <= n1; i++) {
            if (s1[i - 1] == s3[i - 1] and dp[i - 1][0]) {
                dp[i][0] = true;
            }
        }
        for (int i = 1; i <= n2; i++) {
            if (s2[i - 1] == s3[i - 1] and dp[0][i - 1]) {
                dp[0][i] = true;
            }
        }

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                dp[i][j] = (dp[i][j - 1] and s2[j - 1] == s3[i + j - 1]) 
                        or (dp[i - 1][j] and s1[i - 1] == s3[i + j - 1]);
            }
        }
        return dp[n1][n2];
    }


    // Top down DP - Accepted
    /*
    int isInterleaveRecurDPUtils(vector <vector <int> > &dp, string s1, string s2, string s3, int k = 0, int i = 0, int j = 0) {
        if(k == s3.length()) {
            return 1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(i == s1.length()) {
            return dp[i][j] = s2.substr(j, s2.length() - j) == s3.substr(k, s3.length() - k);
        }
        if(j == s2.length()) {
            return dp[i][j] = s1.substr(i, s1.length() - i) == s3.substr(k, s3.length() - k);
        }

        if(s3[k] == s1[i] and s3[k] == s2[j]) {
            return dp[i][j] = isInterleaveRecurDPUtils(dp, s1, s2, s3, k + 1, i + 1, j) |
                              isInterleaveRecurDPUtils(dp, s1, s2, s3, k + 1, i, j + 1);
        }

        if(s3[k] == s1[i]) {
            return dp[i][j] = isInterleaveRecurDPUtils(dp, s1, s2, s3, k + 1, i + 1, j);
        }
        if(s3[k] == s2[j]) {
            return dp[i][j] = isInterleaveRecurDPUtils(dp, s1, s2, s3, k + 1, i, j + 1);
        }
    }

    bool isInterleaveRecurDP(string s1, string s2, string s3) {
        size_t n = s3.length(), n1 = s1.length(), n2 = s2.length();
        vector <vector <int> > dp(n1 + 1, vector <int> (n2 + 1, -1));
        if(n1 + n2 != n) return false;
        if(s3.empty() and s1.empty() and s2.empty()) return true;
        return isInterleaveRecurDPUtils(dp, s1, s2, s3);
    }
    */

    // Recursion - TLE
    /*
    bool isInterleaveUtils(string s1, string s2, string s3) {
        if(s3.empty()) {
            return true;
        }
        if(s1.empty()) {
            return s2 == s3;
        }
        if(s2.empty()) {
            return s1 == s3;
        }

        size_t n = s3.length(), n1 = s1.length(), n2 = s2.length();
        if(s3[0] == s1[0] and s3[0] == s2[0])
            return isInterleaveUtils(s1.substr(1, n1 - 1), s2, s3.substr(1, n - 1)) or
                   isInterleaveUtils(s1, s2.substr(1, n2 - 1), s3.substr(1, n - 1));

        if(s3[0] == s1[0]) return isInterleaveUtils(s1.substr(1, n1 - 1), s2, s3.substr(1, n - 1));
        if(s3[0] == s2[0]) return isInterleaveUtils(s1, s2.substr(1, n2 - 1), s3.substr(1, n - 1));
    }

    bool isInterleave(string s1, string s2, string s3) {
        size_t n = s3.length(), n1 = s1.length(), n2 = s2.length();
        if(n1 + n2 != n) return false;
        if(s3.empty() and s1.empty() and s2.empty()) return true;
        return isInterleaveUtils(s1, s2, s3);
    }
    */
};