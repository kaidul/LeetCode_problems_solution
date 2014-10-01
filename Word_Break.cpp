class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        //return wordBreakHelper(s, dict, 0);
        // dp[i] = true if string 0...i can be formed with dictionary words
        bool dp[s.length() + 1];
        memset(dp, false, sizeof dp);
        dp[0] = true;
        for(int i = 0, n = s.length(); i < n; ++i) {
            if(!dp[i]) continue;
            for(unordered_set<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
                int len = (*it).length();
                int end = i + len;
                if(end > s.length()) continue;
                if(dp[end]) continue;
                if(s.substr(i, len) == *it) dp[end] = true; 
            }
        }
        return dp[s.length()];

        // O(n^3) solution
        /*
        vector <vector<bool> > dp(s.length(), vector<bool>(s.length(), false) );
        for(int i = 0; i < s.length(); ++i) {
            for(int j = 0; j < s.length(); ++j) {
                if(dict.find(s.substr(i, j - i + 1)) != dict.end())
                    dp[i][j] = true;
            }
        }
        for(int i = 0; i < s.length(); ++i) {
            for(int j = 0; j < s.length(); ++j) {
                for(int k = i; k <= j; k++) {
                    if(!dp[i][j]) dp[i][j] = dp[i][k] and dp[k + 1][j];
                }
            }
        }
        return dp[0][s.length() - 1];
        */
    }
    
    // normal recursion.TLE
    bool wordBreakHelper(string s, unordered_set<string> dict, int start) {
        if(start == s.length()) return true;
        for(unordered_set<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
            int len = (*it).length();
            int end = start + len;
            if(end > s.length()) continue;
            if(s.substr(start, len) == *it) {
                if(wordBreakHelper(s, dict, end)) return true;
            }
        }
        return false;
    }
};