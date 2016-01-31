class Solution {
public:
    // other approaches: http://articles.leetcode.com/2010/10/searching-2d-sorted-matrix-part-ii.html
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        if(n == 0) return false;
        int m = matrix[0].size();
        if(m == 0) return false;
        
        // binary search on each row O(nlog m)
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