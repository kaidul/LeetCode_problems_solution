class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        if(n == 0) return 0;
        vector<vector<int>> row(m, vector<int>(n, 0));
        vector<vector<int>> col(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; ++i) {
            int cnt = 0;
            for(int j = 0; j < n; ++j) {
                int start = j;
                while(j < n and grid[i][j] != 'Y') {
                    cnt += (grid[i][j] == 'X'); ++j;
                }
                for(int k = start; k < j; ++k) {
                    if(grid[i][k] == '0') {
                        row[i][k] = cnt;
                    }
                }
                cnt = 0;
            }
        }
        
        for(int j = 0; j < n; ++j) {
            int cnt = 0;
            for(int i = 0; i < m; ++i) {
                int start = i;
                while(i < m and grid[i][j] != 'Y') {
                    cnt += (grid[i][j] == 'X'); ++i;
                }
                for(int k = start; k < i; ++k) {
                    if(grid[k][j] == '0') {
                        col[k][j] = cnt;
                    }
                }
                cnt = 0;
            }
        }
        
        int result = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '0') {
                    result = max(result, row[i][j] + col[i][j]);    
                }
            }
        }
        
        return result;
    }
};