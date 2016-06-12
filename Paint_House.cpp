// top down
class Solution {
    int minCost(int indx, int color, vector<vector<int>> const& costs, vector<vector<bool>>& visited, vector<vector<int>>& dp) {
        if(indx == (int)costs.size()) {
            return 0;
        }
        if(visited[indx][color]) {
            return dp[indx][color];
        }
        visited[indx][color] = true;
        int& ret = dp[indx][color];
        for(int i = 0; i < 3; ++i) {
            if(i == color) { continue; }
            ret = min(ret, costs[indx][color] + minCost(indx + 1, i, costs, visited, dp));
        }
        return ret;
    }
    
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.empty()) return 0;
        int n = (int)costs.size();
        int m = (int)costs[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        return min(minCost(0, 0, costs, visited, dp), 
                min(minCost(0, 1, costs, visited, dp),
                    minCost(0, 2, costs, visited, dp)));
    }
};

// bottom-up
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.empty()) return 0;
        int n = (int)costs.size();
        int m = (int)costs[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        
        for(int i = 0; i < m; ++i) {
            dp[0][i] = costs[0][i];
        }
        
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                dp[i][j] = costs[i][j] + min(dp[i - 1][(j + 1) % m], dp[i - 1][(j + 2) % m]);
            }
        }
        return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    }
};

// space optimized
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.empty()) return 0;
        int n = (int)costs.size();
        int m = (int)costs[0].size();
        vector<vector<int>> dp(2, vector<int>(m, INT_MAX));
        
        for(int i = 0; i < m; ++i) {
            dp[0][i] = costs[0][i];
        }
        
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int k = i % 2;
                int l = (k + 1) % 2;
                dp[k][j] = costs[i][j] + min(dp[l][(j + 1) % m], dp[l][(j + 2) % m]);
            }
        }
        int k = (n & 1) ? 0 : 1;
        return min(dp[k][0], min(dp[k][1], dp[k][2]));
    }
};