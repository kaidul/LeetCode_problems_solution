class Solution {
    int LIS(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<int> dp(n, 1);
        int result = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
    bool static compareFunc(vector<int> const& lhs, vector<int> const& rhs) {
        if(lhs[0] == rhs[0]) {
            return lhs[1] < rhs[1];
        }
        return lhs[0] < rhs[0];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), compareFunc);
        return LIS(pairs);
    }
};