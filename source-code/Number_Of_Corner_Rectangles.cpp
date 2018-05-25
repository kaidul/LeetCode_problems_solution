class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int rows = (int)grid.size();
        int cols = (int)grid.at(0).size();
        vector<vector<int>> columnPair(rows, vector<int>(cols, 0));
        int result = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j]) {
                    for(int k = j + 1; k < cols; k++) {
                        if(grid[i][k]) {
                            result += columnPair[j][k];
                            columnPair[j][k]++;
                        }
                    }    
                }
            }
        }
        return result;
    }
};
