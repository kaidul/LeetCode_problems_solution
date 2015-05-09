class Solution {
public:
    /*
    // wrong algorithm
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n < 2) return n;
        vector<vector<int> > dp(s.length(), vector<int>(s.length(), 0));
        for(int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for(int j = i + 1; j < n; ++j) {
                dp[i][j] = (s[i] != s[j]) ? dp[i + 1][j - 1] + 2 : max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
        return dp[0][n - 1];
    }
    */
    /* wrong algorithm (also TLE)
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n < 2) return n;
        vector<vector<bool> > dp(s.length(), vector<bool>(s.length(), true));
        int maxLength = 1;
        for(int i = n - 1; i >= 0; --i) {
            // dp[i][i] = true;
            for(int j = i + 1; j < n; ++j) {
                dp[i][j] = s[i] != s[j] and dp[i + 1][j - 1];
                if(dp[i][j]) {
                    int len = j - i + 1;
                    maxLength = max(maxLength, len);
                }
            }
        }
        return maxLength;
    }
    */
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n < 2) return n;
        bool exist[256] = {false};
        int start = 0, end = 0;
        int maxLen = 0;
        for(int end = 0; end < n; ++end) {
            if(exist[s[end]]) {
                maxLen = max(maxLen, end - start);
                while(s[start] != s[end]) {
                    exist[s[start++]] = false;
                }
                start++;
            } else {
                exist[s[end]] = true;    
            }
        }
        maxLen = max(maxLen, n - start);
        return maxLen;
    }
};