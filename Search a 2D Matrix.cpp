class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        if(n == 0) return false;
        int m = matrix[0].size();
        if(m == 0) return false;

        int idx, start = 0, end = m - 1;
        for(int i = 0; i < n; ++i) {
            if(matrix[i][start] <= target and target <= matrix[i][end]) {
                idx = i;
                while(start < end) {
                    int mid = start + (end - start) / 2;
                    if(target < matrix[idx][mid]) end = mid - 1;
                    else if(target > matrix[idx][mid]) start = mid + 1;
                    else return true;
                }
                return matrix[i][start] == target;
            }
        }
        
        return false;
    }
};