class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int n = matrix.size();
        if(n == 0) return result;
        int m = matrix[0].size();
        if(m == 0) return result;
        result.resize(m * n);
        int row = 0, col = 0, d = 0;
        int dir[2][2] = {{-1, 1}, {1, -1}};
        
        for (int i = 0; i < m * n; i++) {
            result[i] = matrix[row][col];
            row += dir[d][0];
            col += dir[d][1];
            
            if (row >= n) { row = n - 1; col += 2; d = 1 - d;}
            if (col >= m) { col = m - 1; row += 2; d = 1 - d;}
            if (row < 0)  { row = 0; d = 1 - d;}
            if (col < 0)  { col = 0; d = 1 - d;}
        }
        return result;
    }
};