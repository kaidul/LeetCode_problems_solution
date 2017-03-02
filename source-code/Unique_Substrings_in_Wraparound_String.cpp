class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26, 0); // dp[i] = largest sequence ended with character i
        int len = 0;
        for(int i = 0; i < p.length(); i++) {
            if(i > 0 and (p[i] - p[i - 1] == 1 or p[i - 1] - p[i] == 25)) {
                len++;
            } else {
                len = 1;
            }
            int indx = p[i] - 'a';
            dp[indx] = max(dp[indx], len);
        }
        int result = 0;
        for(int i = 0; i < 26; i++) {
            result += dp[i];
        }
        
        return result;
    }
};