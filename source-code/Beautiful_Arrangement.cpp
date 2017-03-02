class Solution {
    int countArrangement(int indx, int mask, const int N, vector<vector<int>>& dp) {
        if(indx > N) {
            return 1;
        }
        if(dp[indx][mask] != -1) {
            return dp[indx][mask];
        }
        int ret = 0;
        for(int i = 1; i <= N; i++) {
            if(!(mask & (1 << i)) and (indx % i == 0 or i % indx == 0)) {
                ret += countArrangement(indx + 1, mask | (1 << i), N, dp);
            }
        }
        return dp[indx][mask] = ret;
    }
    
public:
    int countArrangement(int N) {
        vector<vector<int>> dp(N + 1, vector<int>((1 << N) << 1, -1));
        return countArrangement(1, 0, N, dp);
    }
};