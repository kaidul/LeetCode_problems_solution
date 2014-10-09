class Solution {
public:
    int minimumTotal(int x, int y, vector<vector<int> > &triangle, vector<vector<int> > &dp) {
        if(x == triangle.size()) return 0;
        if(dp[x][y] != -1) return dp[x][y];
        return dp[x][y] = triangle[x][y] + min(minimumTotal(x + 1, y, triangle, dp), minimumTotal(x + 1, y + 1, triangle, dp));
    }

    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.size() < 0) return 0;
        vector<vector<int> > dp(triangle.size(), vector<int>(triangle.size(), -1));
        return minimumTotal(0, 0, triangle, dp);
    }
};