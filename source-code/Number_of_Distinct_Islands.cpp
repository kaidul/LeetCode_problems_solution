class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool isValid(int x, int y, vector<vector<int>>& grid) {
        return x >= 0 and y >= 0 and x < grid.size() and y < grid[0].size();
    }
    
    int dfs(int x, int y, const int offsetX, const int offsetY, vector<vector<int>>& grid, vector<pair<int, int>>& boundaries) {
        grid[x][y] = 0;
        bool boundary = false;
        int count = 0;
        for(int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(isValid(newX, newY, grid) and grid[newX][newY]) {
                count += dfs(newX, newY, offsetX, offsetY, grid, boundaries);
            } else {
                boundary = true;
            }
        }
        if(boundary) {
            boundaries.push_back({x - offsetX, y - offsetY});
        }
        return 1 + count;
    }
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if(grid.empty()) {
            return 0;
        }
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int, int>>> islandSet;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) {
                    vector<pair<int, int>> boundaries;
                    int len = dfs(i, j, i, j, grid, boundaries);
                    sort(boundaries.begin(), boundaries.end());
                    islandSet.insert(boundaries);
                }
            }
        }
        return islandSet.size();
    }
};