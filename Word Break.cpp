class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        //return wordBreakHelper(s, dict, 0);
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
    }
    
    // normal recursion.TLE
    bool wordBreakHelper(string &s, unordered_set<string> dict, int start) {
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