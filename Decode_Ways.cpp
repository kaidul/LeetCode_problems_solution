class Solution {
public:
    bool valid(string s) {
        if (s.size() == 0) {
            return false;
        }
        if (s[0] == '0') {
            return false;
        }
        if (s.size() == 2) {
            if (s[0] > '2' || (s[0] == '2' && s[1] > '6')) {
                return false;
            }
        }
        return true;
    }
    
	int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        vector<int> dp(s.size(), 0);
        if (s[0] != '0') {
            dp[0] = 1;
        }
        if (s.size() == 1) {
            return dp[0];
        }
        if (valid(s.substr(0, 2))) {
            dp[1]++;
        }
        if (s[0] != '0' && s[1] != '0') {
            dp[1]++;
        }

        //DP
        for (int i = 2; i < s.size(); i++) {
            if (s[i] != '0') {
                dp[i] += dp[i - 1];
            }
            if (valid(s.substr(i - 1, 2))) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[s.size() - 1];
    }
};