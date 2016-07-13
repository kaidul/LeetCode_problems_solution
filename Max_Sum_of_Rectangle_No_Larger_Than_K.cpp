// O(n^3 logn)
// AC
class Solution {
    // maximum subarray sum less than or equal to k
    // O(nlogn)
    int subarraySum(vector<int>& arr, int k) {
        int n = (int)arr.size(); 
        int cumSum = 0;
        int maxSum = INT_MIN;
        set<int> cumSet;
        for(int i = 0; i < n; ++i) {
            cumSum += arr[i];
            set<int>::iterator it = cumSet.upper_bound(cumSum - k - 1);
            if(it != cumSet.end()) {
                maxSum = max(maxSum, cumSum - *it);
            }
            if(cumSum <= k) {
                maxSum = max(maxSum, cumSum);
            }
            cumSet.insert(cumSum);
        }
        return maxSum;
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = (int)matrix.size();
        if(m == 0) return 0;
        int n = (int)matrix[0].size();
        if(n == 0) return 0;
        
        vector<int> tmp(m);
        int result = INT_MIN;
        for(int left = 0; left < n; ++left) {
            fill(tmp.begin(), tmp.end(), 0);
            for(int right = left; right < n; ++right) {
                for(int i = 0; i < m; ++i) {
                    tmp[i] += matrix[i][right];
                }
                int sum = kadane(tmp, k);
                result = max(result, sum);
            }
        }
        
        return result;
    }
};

// TLE
// Exclusion-Inclusion principle O(n^4)
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = (int)matrix.size();
        if(m == 0) return 0;
        int n = (int)matrix[0].size();
        if(n == 0) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                dp[i][j] += matrix[i][j];
                if(i > 0) {
                    dp[i][j] += dp[i - 1][j];
                }
                if(j > 0) {
                    dp[i][j] += dp[i][j - 1];
                }
                if(i > 0 and j > 0) {
                    dp[i][j] -= dp[i - 1][j - 1];
                }
            }
        }
        int result = INT_MIN;
        for(int r1 = 0; r1 < m; ++r1) {
            for(int c1 = 0; c1 < n; ++c1) {
                for(int r2 = r1; r2 < m; ++r2) {
                    for(int c2 = c1; c2 < n; ++c2) {
                        int sum = dp[r2][c2];
                        if(r1 > 0) {
                            sum -= dp[r1 - 1][c2];
                        }
                        if(c1 > 0) {
                            sum -= dp[r2][c1 - 1];
                        }
                        if(r1 > 0 and c1 > 0) {
                            sum += dp[r1 - 1][c1 - 1];
                        }
                        result = max(result, ((sum <= k) ? sum : INT_MIN));
                    }
                }
            }
        }
        
        return result;
    }
};