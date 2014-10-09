class Solution {
public:
    /* MLE
    string longestPalindrome(string s) {
        if(s.length() < 2) return s;
        vector<vector<int> >  dp(s.length(), vector<int>(s.length(), 0));
        int n = s.length();
        int start = 0, end = 0, Max = 1;
        for(int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for(int j = i + 1; j < n; ++j) {
                dp[i][j] = (s[i] == s[j] and (j - i < 3 or dp[i + 1][j - 1] == j - 1 - i))
                           ? dp[i + 1][j - 1] + 2
                           : max(dp[i][j - 1], dp[i + 1][j]);
                if(dp[i][j] > Max) {
                    Max = dp[i][j];
                    start = i, end = j;
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
    */
    /* TLE
    string longestPalindrome(string s) {
        if(s.length() < 2) return s;
        vector <vector<bool> > dp(s.length(), vector<bool>(s.length(), false));
        int start = 0, maxLen = 1;
        int n = s.length();
        for(int i = n - 1; i >= 0; --i) {
            dp[i][i] = true;
            for(int j = i + 1; j < n; ++j) {
                dp[i][j] = (s[i] == s[j] and (j - i < 3 or dp[i + 1][j - 1])) ? true : false;
                if(dp[i][j]) {
                    int len = j - i + 1;
                    if(len > maxLen) {
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
    */
    string expandAroundCenter(string s, int c1, int c2) {
        int l = c1, r = c2;
        int n = s.length();
        while (l >= 0 and r < n and s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }

    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2) return s;
        string longest = s.substr(0, 1);  // a single char itself is a palindrome
        for (int i = 0; i < n - 1; i++) {
            string p1 = expandAroundCenter(s, i, i);
            if (p1.length() > longest.length())
                longest = p1;

            string p2 = expandAroundCenter(s, i, i + 1);
            if (p2.length() > longest.length())
                longest = p2;
        }
        return longest;
    }
};