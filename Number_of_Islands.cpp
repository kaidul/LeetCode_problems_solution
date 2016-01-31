class Solution {
public:
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    vector<vector<char> > grid;
    int n, m;
    
    int dfs(int x, int y) {
        grid[x][y] = '0';
        for(int i = 0; i < 4; ++i) {
            int X = x + dx[i];
            int Y = y + dy[i];
            if(X >= 0 and Y >= 0 and X < n and Y < m and grid[X][Y] == '1') {
                dfs(X, Y);        
            }
        }
    }
    
    int numIslands(vector<vector<char>> &grid) {
        this->grid = grid;
        int result = 0;
        n = grid.size();
        if(n < 1) return result;
        m = grid[0].size();
        if(m < 1) return result;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(this->grid[i][j] == '1') {
                    result++;
                    dfs(i, j);
                }
            }
        }
        return result;
    }
};