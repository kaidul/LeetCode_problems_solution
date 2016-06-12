class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.empty()) return 0;
        int n = (int)envelopes.size();
        sort(envelopes.begin(), envelopes.end());

        // O(n^2) LIS
        vector<int> dp(n, 1);
        int result = dp[0];
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(envelopes[i].first > envelopes[j].first and envelopes[i].second > envelopes[j].second) {
                    dp[i] = max(dp[i], dp[j] + 1);    
                }
            }
            result = max(result, dp[i]);
        }
        
        return result;
    }
};