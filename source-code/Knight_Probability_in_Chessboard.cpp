class Solution {
    int dx[8] = {-2, -2, -1, 1, 2, 2, -1, 1};
    int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
    double knightProbability(int N, int k, int x, int y, vector<vector<vector<double>>>& dp) {
        if (k == 0) {
            return 1.0;
        }
        if (dp[k][x][y] != -1.0) {
            return dp[k][x][y];
        }
        dp[k][x][y] = 0;
        for(int i = 0; i < 8; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(newX >= 0 and newY >= 0 and newX < N and newY < N) {
                dp[k][x][y] += knightProbability(N, k - 1, newX, newY, dp);
            }
        }
        return dp[k][x][y];
    }
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp(K + 1, vector<vector<double>>(N, vector<double>(N, -1.0)));
        
        return knightProbability(N, K, r, c, dp) / pow(8, K);
    }
};

// bottom-up
class Solution {
    int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp(K + 1, vector<vector<double>>(N, vector<double>(N, 0.0)));
        dp[0][r][c] = 1;
        for(int step = 1; step <= K; step++) {
            for(int x = 0; x < N; x++) {
                for(int y = 0; y < N; y++) {
                    for(int i = 0; i < 8; i++) {
                        int newX = x + dx[i];
                        int newY = y + dy[i];
                        if(newX >= 0 and newY >= 0 and newX < N and newY < N) {
                            dp[step][x][y] += dp[step - 1][newX][newY] * 0.125;
                            // or dp[step][newX][newY] += dp[step - 1][x][y] * 0.125;
                        }
                    }
                }
            }
        }
        
        double result = 0.0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                result += dp[K][i][j];
            }
        }
        
        return result;
    }
};