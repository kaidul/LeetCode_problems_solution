// 3 ms
// can be done with stack instead of leftCount
class Solution {
    bool checkValidString(int indx, string const& s, int leftCount, vector<vector<int>>& dp) {
        if(indx == s.length()) {
            return leftCount == 0;
        }
        if(dp[indx][leftCount] != -1) {
            return dp[indx][leftCount];
        }
        if(s[indx] == '(') {
            if(checkValidString(indx + 1, s, leftCount + 1, dp)) {
                return dp[indx][leftCount] = true;
            }
        }
        else if(s[indx] == '*') {
            // empty
            if(checkValidString(indx + 1, s, leftCount, dp)) {
                return dp[indx][leftCount] = true;
            }
            
            // left parenthesis
            if(checkValidString(indx + 1, s, leftCount + 1, dp)) {
                return dp[indx][leftCount] = true;
            }
            
            // right parenthesis
            if(leftCount > 0) {
                if(checkValidString(indx + 1, s, leftCount - 1, dp)) {
                    return dp[indx][leftCount] = true;
                }
            }
        }
        else if(s[indx] == ')') {
            if(leftCount > 0) {
                if(checkValidString(indx + 1, s, leftCount - 1, dp)) {
                    return dp[indx][leftCount] = true;
                }
            }
        }
        
        return dp[indx][leftCount] = false;
    }
    
public:
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length() + 1, -1));
        return checkValidString(0, s, 0, dp);
    }
};

// 22 ms
// Solution: Sakibul Mowla
class Solution {
public:
    
    vector<vector<int>> dp;

    int checkValidString(string const& s, int strt, int endd) {
        if (strt > endd) return true;
        if (strt == endd) return s[strt] == '*';

        int& ret = dp[strt][endd];
        if (ret != -1) return ret;

        if (s[strt] == '*') {
            if(checkValidString(s, strt + 1, endd)) {
                return ret = true;
            }
            if (s[endd] == '*' || s[endd] == ')')
                if(checkValidString(s, strt + 1, endd - 1)) {
                    return ret = true;
                }
            
            
        }
        if (s[endd] == '*') {
            if(checkValidString(s, strt, endd - 1)) {
                return ret = true;
            }
            if (s[strt] == '*' || s[strt] == '(')
                if(checkValidString(s, strt + 1, endd - 1)) {
                    return ret = true;
                }
        }
        if (s[strt] == '(' && s[endd] == ')') {
            if(checkValidString(s, strt + 1, endd - 1)) {
                return ret = true;
            }
        }

        for (int k = strt; k < endd; k++) {
            if(checkValidString(s, strt, k) && checkValidString(s, k + 1, endd)) {
                return ret = true;
            }
        }
        
        return ret = false;
    }

    bool checkValidString(string s) {
        int n = s.size();
        dp = vector<vector<int>> (n, vector<int> (n, -1));
        return checkValidString(s, 0, n - 1);
    }
};