class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if(n == 0) return;
        for(int i = 0; i < (n / 2); ++i) {
            int top = i, bottom = n - 1 - i;
            int left = top, right = bottom;
            for(int j = i; j < n - 1 - i; ++j) {
                int tmp = matrix[top][j];
                matrix[top][j] = matrix[n - 1 - j][left];
                matrix[n - 1 - j][left] = matrix[bottom][n - 1 - j];
                matrix[bottom][n - 1 - j] = matrix[j][right];
                matrix[j][right] = tmp;
            }
        }
    }
};