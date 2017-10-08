class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    bool isValid(int x, int y, vector<vector<int>>& grid) {
        return x >= 0 and y >= 0 and x < grid.size() and y < grid[0].size();
    }
    int dfs(int x, int y, vector<vector<int>>& grid) {
        grid[x][y] = 0;
        int count = 0;
        for(int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(isValid(newX, newY, grid) and grid[newX][newY]) {
                count += dfs(newX, newY, grid);
            }
        }
        return 1 + count;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int maxLen = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j]) {
                    maxLen = max(maxLen, dfs(i, j, grid));
                }
            }
        }
        return maxLen;
    }
};