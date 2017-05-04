class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int rows = (int)nums.size();
        int cols = (int)nums[0].size();
        if (r * c != rows * cols) {
            return nums;
        }
        vector<vector<int>> reshapedMatrix(r, vector<int>(c));
        for(int i = 0, x = 0, y = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                reshapedMatrix[x][y++ % c] = nums[i][j];
                if(y % c == 0) {
                    x++;
                }
            }
        }
        return reshapedMatrix;
    }
};