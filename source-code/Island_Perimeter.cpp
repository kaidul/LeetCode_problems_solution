class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = (row > 0) ? grid[0].size() : 0;
        int result = 0;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j]) {
                    result += (i == 0 or !grid[i - 1][j]);
                    result += (i + 1 == row or !grid[i + 1][j]);
                    result += (j == 0 or !grid[i][j - 1]);
                    result += (j + 1 == col or !grid[i][j + 1]);
                }
            }
        }
        return result;
    }
};