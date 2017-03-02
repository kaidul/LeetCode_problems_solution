class Solution {
    const int dx[4] = {0, -1, 0, 1};
    const int dy[4] = {-1, 0, 1, 0};
    
    inline bool isValid(int x, int y, vector<vector<int>> const& grid, vector<vector<bool>> const& visited) const {
        return (x >= 0 and y >= 0 and x < (int)grid.size() and y < (int)grid[0].size() and !visited[x][y] and !grid[x][y]);
    }
    
    void bfs(int x, int y, vector<vector<int>> const& grid, vector<vector<int>>& dist, vector<vector<int>>& cnt) {
        int m = (int)grid.size(), n = (int)grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        vector<pair<int, int>> prevLevel{{x, y}}, currLevel;
        visited[x][y] = true;
        int depth = 0;
        
        while(!prevLevel.empty()) {
            ++depth;
            currLevel.clear();
            for(int i = 0; i < (int)prevLevel.size(); ++i) {
                int x = prevLevel[i].first, y = prevLevel[i].second;
                for(int k = 0; k < 4; ++k) {
                    int newX = x + dx[k], newY = y + dy[k];
                    if(isValid(newX, newY, grid, visited)) {
                        visited[newX][newY] = true;
                        dist[newX][newY] += depth;
                        ++cnt[newX][newY];
                        currLevel.push_back({newX, newY});
                    }
                }
            }
            swap(prevLevel, currLevel);
        }
        
    }
    
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        if(m == 0) return 0;
        int n = (int)grid[0].size();
        if(n == 0) return 0;
        
        vector<vector<int>> dist(m, vector<int>(n, 0));
        vector<vector<int>> cnt(m, vector<int>(n, 0));
        
        int buildings = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    buildings++;
                    bfs(i, j, grid, dist, cnt);
                }
            }
        }
        int result = INT_MAX;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(cnt[i][j] == buildings and dist[i][j] < result) {
                    result = dist[i][j];
                }
            }
        }
        
        return ((result != INT_MAX) ? result : -1);
    }
};