// optimized version. AC :)
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int row1 = A.size();
        int col1 = A[0].size();
        int row2 = B.size();
        int col2 = B[0].size();
        vector<vector<int>> product(row1, vector<int>(col2, 0));
        
        for(int i = 0; i < row1; i++) {
            bool zeroRow = true;
            for(int p = 0; p < col1; ++p) {
                if(A[i][p] != 0) {
                    zeroRow = false;
                    break;
                }
            }
            if(zeroRow) continue;
            for(int j = 0; j < col2; ++j) {
                bool zeroCol = true;
                for(int q = 0; q < row2; ++q) {
                    if(B[q][j] != 0) {
                        zeroCol = false;
                        break;
                    }
                }
                if(zeroCol) continue;
                for(int k = 0; k < col1; ++k) {
                    if(A[i][k] == 0 or B[k][j] == 0) continue;    
                    product[i][j] += (A[i][k] * B[k][j]);
                }
            }
        }
        return product;
    }
};
// TLE
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int row1 = A.size();
        int col1 = A[0].size();
        int row2 = B.size();
        int col2 = B[0].size();
        vector<vector<int>> product(row1, vector<int>(col2, 0));
        for(int i = 0; i < row1; i++) {
            for(int j = 0; j < col2; ++j) {
                for(int k = 0; k < col1; ++k) { 
                    product[i][j] += (A[i][k] * B[k][j]);
                }
            }
        }
        return product;
    }
};