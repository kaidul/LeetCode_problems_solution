class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int totalBricksAttached(int x, int y, vector<vector<int>>& grid) {
        if (grid[x][y] != 1) {
            return 0;
        }
        grid[x][y] = 2;
        int count = 0;
        for (int i = 0; i < sizeof(dx) / sizeof(dx[0]); i++) {
            int neighX = x + dx[i];
            int neighY = y + dy[i];
            if (neighX >= 0 and neighY >= 0 and neighX < grid.size() and neighY < grid[0].size()
               and grid[neighX][neighY] == 1) {
                count += totalBricksAttached(neighX, neighY, grid);
            }
        }
        return 1 + count;
    }
    
    bool isConnectedToTop(int x, int y, vector<vector<int>>& grid) {
        if (x == 0) {
            return true;
        }
        for (int i = 0; i < sizeof(dx) / sizeof(dx[0]); i++) {
            int neighX = x + dx[i];
            int neighY = y + dy[i];
            if (neighX >= 0 and neighY >= 0 and neighX < grid.size() and neighY < grid[0].size() 
                and grid[neighX][neighY] == 2) {
                    return true;
            }
        }
        return false;
    }
    
    vector<int> searchFallingBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        vector<int> result(hits.size(), 0);
        for (int i = hits.size() - 1; i >= 0; i--) {
            vector<int>& hit = hits[i];
            int x = hit[0], y = hit[1];
            if (grid[x][y] == 0) {
                grid[x][y] = 1;
                if (isConnectedToTop(x, y, grid)) {
                    result[i] = totalBricksAttached(x, y, grid) - 1;
                }
            }
        }
        return result;
    }
    
    void removeHits(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        for (vector<int> hit : hits) {
            int x = hit[0], y = hit[1];
            grid[x][y] = grid[x][y] - 1;
        }
    }
    
    void markBricks(vector<vector<int>>& grid) {
        for (int i = 0; i < grid[0].size(); i++) {
            totalBricksAttached(0, i, grid);
        }
    }
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        removeHits(grid, hits);
        markBricks(grid);
        return searchFallingBricks(grid, hits);
    }
};

// TLE
class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int totalBricksAttached(vector<vector<int>>& grid, vector<vector<bool>>& isBrick, int x, int y) {
        isBrick[x][y] = true;
        int count = 0;
        for (int i = 0; i < sizeof(dx) / sizeof(dx[0]); i++) {
            int neighX = x + dx[i];
            int neighY = y + dy[i];
            if (neighX >= 0 and neighY >= 0 and neighX < grid.size() and neighY < grid[0].size()
               and grid[neighX][neighY] and !isBrick[neighX][neighY]) {
                isBrick[neighX][neighY] = true;
                count += totalBricksAttached(grid, isBrick, neighX, neighY);
            }
        }
        return 1 + count;
    }
    
    int totalBricksAttached(vector<vector<int>>& grid, vector<vector<bool>>& isBrick) {
        int totalBricks = 0;
        for (int i = 0; i < grid[0].size(); i++) {
            if (grid[0][i] and !isBrick[0][i]) {
                totalBricks += totalBricksAttached(grid, isBrick, 0, i);
            }
        }
        return totalBricks;
    }
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        vector<vector<bool>> isBrick;
        
        isBrick = vector<vector<bool>>(grid.size(), vector<bool> (grid[0].size(), false));
        int totalBricks = totalBricksAttached(grid, isBrick);
        
        vector<int> result;
        for (vector<int> hit : hits) {
            int x = hit[0], y = hit[1];
            if (!isBrick[x][y]) {
                result.push_back(0);
                continue;
            }
            grid[x][y] = 0;
            totalBricks--;
            isBrick = vector<vector<bool>>(grid.size(), vector<bool> (grid[0].size(), false));
            int fallenBricks = totalBricks - totalBricksAttached(grid, isBrick);
            result.push_back(fallenBricks);
            totalBricks -= fallenBricks;
        }
        
        return result;
    }
};