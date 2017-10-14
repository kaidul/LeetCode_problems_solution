// correctness OK, but RE for recursion stack overflow
class Solution {
    const int MOD = 1000000000 + 7;
    int numDecodings(int indx, string& s, vector<int>& dp) {
        if(indx >= s.length()) {
            return 1;
        }
        if(dp[indx] != -1) {
            return dp[indx];
        }
        int ret = 0;
        if(s[indx] != '*') {
            if(s[indx] == '0' and indx + 1 < s.length and s[indx + 1] == '0') {
                return 0;
            }
            ret = (ret + numDecodings(indx + 1, s, dp)) % MOD;
            if(indx + 1 < s.length()) {
                if(s[indx + 1] != '*') {
                    if(s[indx] == '1' or (s[indx] == '2' and s[indx + 1] <= '6')) {
                        ret = (ret + numDecodings(indx + 2, s, dp)) % MOD;
                    }
                } else if(s[indx + 1] == '*') {
                    if(s[indx] != '0') {
                        if(s[indx] == '1') {
                            ret = (ret + 1LL * numDecodings(indx + 2, s, dp) * 9 % MOD) % MOD;
                        } else if(s[indx] == '2') {
                            ret = (ret + 1LL * numDecodings(indx + 2, s, dp) * 6 % MOD) % MOD;
                        }
                    }
                }
            }
        } else if(s[indx] == '*') {
            ret = (ret + 1LL * numDecodings(indx + 1, s, dp) * 9 % MOD) % MOD;

            if(indx + 1 < s.length()) {
                if(s[indx + 1] != '*') {
                    if(s[indx + 1] <= '6') {
                        ret = (ret + 1LL * numDecodings(indx + 2, s, dp) * 2 % MOD) % MOD;
                    } else {
                        ret = (ret + numDecodings(indx + 2, s, dp)) % MOD;
                    }
                } else if(s[indx + 1] == '*') {
                    ret = (ret + 1LL * numDecodings(indx + 2, s, dp) * 15 % MOD) % MOD;
                }
            }
        }
        if(ret < 0) ret += MOD;
        return dp[indx] = ret % MOD;
    }
public:
    int numDecodings(string s) {
        int n = (int)s.length();
        if(s[0] == '0') {
            return 0;
        }
        vector<int>dp(n, -1);
        return numDecodings(0, s, dp);
    }
};

// same approach, just bottom-up to avoid stack overflow
class Solution {
    const int MOD = 1000000000 + 7;
public:
    int numDecodings(string s) {
        int n = (int)s.length();
        vector<int>dp(n + 1, 0);
        dp[0] = 1;
        if(s[0] == '0') {
            return 0;
        }
        dp[1] = s[0] != '*' ? 1 : 9;
        
        for(int i = 2; i <= n; i++) {
            if(s[i - 1] == '0') {
                if(s[i - 2] == '1' or s[i - 2] == '2') {
                    dp[i] = dp[i - 2];
                } else if(s[i - 2] == '*') { // 10, 20
                    dp[i] = 2LL * dp[i - 2] % MOD;
                } else {
                    return 0;
                }
            }
            else if(s[i - 1] >= '1' and s[i - 1] <= '9') {
                dp[i] = dp[i - 1];
                if(s[i - 2] == '1' or (s[i - 2] == '2' and s[i - 1] <= '6')){
                    dp[i] = (dp[i] + dp[i - 2]) % MOD;
                } 
                else if(s[i - 2] == '*') {
                    if (s[i - 1] <= '6') { // *[1 - 6]
                        dp[i] = (dp[i] + 1LL * dp[i - 2] * 2 % MOD) % MOD;
                    }
                    else { // *[7 - 9]
                        dp[i] = (dp[i] + dp[i - 2]) % MOD;
                    }
                }
            } else if(s[i - 1] == '*') {
                dp[i] = 1LL * dp[i - 1] * 9 % MOD;
                
                if(s[i - 2] == '1') { // 1* (11 - 19)
                    dp[i] = (dp[i] + 1LL * dp[i - 2] * 9 % MOD) % MOD;
                } else if(s[i - 2] == '2') { // 2* (21 - 26)
                    dp[i] = (dp[i] + 1LL * dp[i - 2] * 6 % MOD) % MOD;
                } else if(s[i - 2] == '*') { // ** (11 - 26)
                    dp[i] = (dp[i] + 1LL * dp[i - 2] * 15 % MOD) % MOD;
                }
            }
        }
        return dp[n];
    }
};