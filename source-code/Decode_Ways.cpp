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

    int numDecodingsUtil(string s, int indx, vector<int>& dp) {
        if(indx == (int)s.length()) {
            return 1;
        }
        if(dp[indx] != -1) {
            return dp[indx];
        }
        int ret = 0;
        if(s[indx] != '0') {
            ret += numDecodingsUtil(s, indx + 1, dp);
        }
        if(indx + 1 < s.length() and valid(s.substr(indx, 2))) {
            ret += numDecodingsUtil(s, indx + 2, dp);
        }

        return dp[indx] = ret;
    }
    
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
	// recursive
	// vector<int> dp(s.size(), -1);
        // return numDecodingsUtil(s, 0, dp);

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
