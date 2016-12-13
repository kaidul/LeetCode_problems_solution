// binary search on each row O(nlog m)
/*
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        if(n == 0) return false;
        int m = matrix[0].size();
        if(m == 0) return false;
        
        for(int i = 0; i < n; ++i) {
            int start = 0, end = m - 1;
            if(matrix[i][start] <= target and target <= matrix[i][end]) {
                while(start <= end) {
                    int mid = start + (end - start) / 2;
                    if(target < matrix[i][mid]) {
                        end = mid - 1;
                    } else if(target > matrix[i][mid]) {
                        start = mid + 1;
                    } else 
                        return true;
                }
            }
        }
        return false;
    }
};
*/

// O(n + m) solution
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        if(n == 0) return false;
        
        int i = 0, j = n - 1;
        while(i < m and j >= 0) {
            if(target == matrix[i][j]) {
                return true;
            } else if(target < matrix[i][j]) {
                j--;
            } else {
                ++i;
            }
        }
        return false;
    }
};