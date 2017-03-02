class NumMatrix {
public:
    vector<vector<int>> matrixSum;
    NumMatrix(vector<vector<int>> &matrix) {
        int n = matrix.size();
        if(n == 0) return;
        int m = matrix[0].size();
        if(m == 0) return;
        matrixSum.resize(n, vector<int>(m, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int top = (i > 0) ? matrixSum[i - 1][j] : 0;
                int left = (j > 0) ? matrixSum[i][j - 1] : 0;
                int corner = (i > 0 && j > 0) ? matrixSum[i - 1][j - 1] : 0;
                matrixSum[i][j] = matrix[i][j] + top + left - corner;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int n = matrixSum.size();
        int m = matrixSum[0].size();
        assert(row1 >= 0 && row1 < n and row2 >= 0 && row2 < n and row1 <= row2);
        assert(col1 >= 0 && col1 < m and col2 >= 0 && col2 < m and col1 <= col2);
        int top = (row1 > 0) ? matrixSum[row1 - 1][col2] : 0;
        int left = (col1 > 0) ? matrixSum[row2][col1 - 1] : 0;
        int corner = (row1 > 0 && col1 > 0) ? matrixSum[row1 - 1][col1 - 1] : 0;
        int result = matrixSum[row2][col2] - top - left + corner;
        return result;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);