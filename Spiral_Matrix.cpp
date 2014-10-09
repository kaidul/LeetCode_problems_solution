/* Buggy Shit
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if(matrix.empty()) return result;
        int m = matrix.size(), n = matrix[0].size();
        int len = (m & 1) ? (m + 1) / 2 : m / 2;
        int len2 = (n & 1) ? (n + 1) / 2 : n / 2;
        for(int i = 0, j = 0; i < len and j < len2; ++i, ++j) {

            for(int k = j; k < n - j; ++k)
                result.push_back(matrix[i][k]);

            for(int k = i + 1; k < m - i; ++k)
                result.push_back(matrix[k][n - 1 - j]);

            for(int k = n - 1 - j - 1; k >= j and m - i < m; --k)
                result.push_back(matrix[m - 1 - i][k]);

            for(int k = m - 1 - i - 1; k > i and j < n - 1; --k)
                result.push_back(matrix[k][j]);
        }
        return result;
    }
};
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if (matrix.empty()) { return res; }
        if (matrix.size()==1) { return matrix[0]; }
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool> > mask(m, vector<bool>(n, false));
        int i = 0;
        int j = 0;
        int k = 0;
        res.push_back(matrix[i][j]);
        mask[0][0] = true;
        while (k < m * n - 1) {
            while ((j + 1 < n) and (mask[i][j + 1] == false)) {
                j++;
                k++;
                res.push_back(matrix[i][j]);
                mask[i][j] = true;
            }
             
            while ((i + 1 < m) and (mask[i + 1][j] == false)) {
                i++;
                k++;
                res.push_back(matrix[i][j]);
                mask[i][j] = true;
            }
             
            while ((j > 0) and (mask[i][j - 1] == false)) {
                j--;
                k++;
                res.push_back(matrix[i][j]);
                mask[i][j] = true;
            }
             
            while ((i > 0) and (mask[i - 1][j] == false)) {
                i--;
                k++;
                res.push_back(matrix[i][j]);
                mask[i][j] = true;
            }
        }
        return res;
    }
};