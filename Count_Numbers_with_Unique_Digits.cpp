class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        vector<int> dp(11);
        dp[1] = 10;
        dp[2] = 9 * 9;
        for(int k = 8, i = 3; k > 0; --k, ++i) {
            dp[i] = dp[i - 1] * k;
        }
        for(int i = 2; i <= 10; ++i) {
            dp[i] += dp[i - 1];
        }
        return dp[(n <= 10) ? n : 10];
    }
};