// DP
// dp[i][j] = maximum score player 1 can get from subarray [i... j]
// dp[i][j] = max(nums[i] + sum[i + 1... j] - dp[i + 1][j], nums[j] + sum[i... j - 1] - dp[i][j - 1])
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = (int)nums.size();
        vector<vector<int>> score(n, vector<int>(n));
        vector<int> prefixSum(n + 1);
        prefixSum[0] = 0;
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        for (int len = 1; len <= n; len++) {
            for (int lhs = 0; lhs + len - 1 < n; lhs++) {
                int rhs = lhs + len - 1;
                if (lhs == rhs) {
                    score[lhs][rhs] = nums[lhs];
                }
                /*
                else if (lhs == rhs - 1) {
                    score[lhs][rhs] = max(nums[lhs], nums[rhs]);
                }
                */ 
                else {
                    int pickLeft = nums[lhs] + (prefixSum[rhs + 1] - prefixSum[lhs + 1]) - score[lhs + 1][rhs];
                    int pickRight = nums[rhs] + (prefixSum[rhs] - prefixSum[lhs]) - score[lhs][rhs - 1];
                    score[lhs][rhs] = max(pickLeft, pickRight);
                }
            }
        }
        
        return score[0][n - 1] >= (prefixSum.back() / 2 + prefixSum.back() % 2);
    }
};


// recursive solution
class Solution {
    bool predictTheWinner(int left, int right, int sum1, int sum2, int player, vector<int>& nums) {
        if(left > right) {
            return (sum1 >= sum2);
        }
        if(player == 1) {
            if(predictTheWinner(left + 1, right, sum1 + nums[left], sum2, player ^ 3, nums)) {
                return true;
            }
            if(predictTheWinner(left, right - 1, sum1 + nums[right], sum2, player ^ 3, nums)) {
                return true;
            }
            
            return false;
        }
        
        // else if(player == 2) {
        
        if(!predictTheWinner(left + 1, right, sum1, sum2 + nums[left], player ^ 3, nums)) {
            return false;
        }
        if(!predictTheWinner(left, right - 1, sum1, sum2 + nums[right], player ^ 3, nums)) {
            return false;
        }
        
        return true;
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = (int)nums.size();
        return predictTheWinner(0, n - 1, 0, 0, 1, nums);
    }
};