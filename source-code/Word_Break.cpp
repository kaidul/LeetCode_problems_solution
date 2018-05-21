class Solution {
    // top-down
    bool wordBreak(int indx, string const& s, vector<string>& wordDict, vector<int>& dp) {
        if(indx == s.length()) {
            return true;
        }
        if(dp[indx] != -1) {
            return dp[indx];
        }
        for(string word: wordDict) {
            int len = word.length();
            if(indx + len <= s.length() and s.substr(indx, len) == word and wordBreak(indx + len, s, wordDict, dp)) {
                return dp[indx] = true;
            }
        }
        return dp[indx] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // vector<int> dp(s.length(), -1);
        // return wordBreak(0, s, wordDict, dp);
        
        // bottom-up
        int n = s.length();
        vector<bool> dp(n, false); 
        dp[0] = true;
        for(int i = 0; i < n; ++i) {
            if(dp[i]) {
                for(string const& word : wordDict) {
                    int len = word.length();
                    if(i + len <= n and !dp[i + len] and s.substr(i, len) == word) {
                        dp[i + len] = true;
                    } 
                }
            }
        }
        return dp[n];
        
        /*
        // O(n^3) solution
        int n = (int)s.length();
        vector <vector<bool> > dp(n, vector<bool>(n, false) );
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                if(dict.find(s.substr(i, j - i + 1)) != dict.end())
                    dp[i][j] = true;
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                for(int k = i; k <= j; k++) {
                    if(!dp[i][j]) {
                        dp[i][j] = dp[i][k] and dp[k + 1][j];
                    }
                }
            }
        }
        return dp[0][n - 1];
        */
    }
};