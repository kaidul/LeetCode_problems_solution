class Solution {
    string replaceAll(string subject, string const& search, string const& replace) {
        size_t pos = 0;
        while ((pos = subject.find(search, pos)) != string::npos) {
            subject.replace(pos, search.length(), replace);
            pos += replace.length();
        }
        return subject;
    }
public:
    string encode(string s) {
        int n = s.length();
        vector<vector<string>> dp(n, vector<string>(n));
        for(int len = 1; len <= n; len++) {
            for(int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                string substr = s.substr(i, len);
                dp[i][j] = substr;
                if(len <= 4) continue;
                for(int k = i; k < j; k++) {
                    if((dp[i][k] + dp[k + 1][j]).length() < dp[i][j].length()) {
                        dp[i][j] = dp[i][k] + dp[k + 1][j];
                    }
                }
                for(int k = 1; k <= substr.length() / 2; k++) {
                    string repeatedSubstr = substr.substr(0, k);
                    if(substr.length() % repeatedSubstr.length() == 0 and
                       replaceAll(substr, repeatedSubstr, "").empty()) {
                        string token = to_string(substr.length() / repeatedSubstr.length()) + "[" + dp[i][i + k - 1] + "]";
                        if(token.length() < dp[i][j].length()) {
                            dp[i][j] = token;
                        }
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};