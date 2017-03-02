class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        if(n == 0) return false;
        int m = matrix[0].size();
        if(m == 0) return false;

        // O(log m + log n)
        int leftX = 0, rightX = n - 1;
        while(leftX <= rightX) {
            int midX = leftX + (rightX - leftX) / 2;
            if(target < matrix[midX][0]) {
                rightX = midX - 1;
            } else if(target > matrix[midX][m - 1]) {
                leftX = midX + 1;
            } else { // matrix[midX][0] <= target and target <= matrix[midX][m - 1]
                int leftY = 0, rightY = m - 1;
                while(leftY <= rightY) {
                    int midY = leftY + (rightY - leftY) / 2;
                    if(target < matrix[midX][midY]) {
                        rightY = midY - 1;
                    } else if(target > matrix[midX][midY]) {
                        leftY = midY + 1;
                    } else 
                        return true;
                }
                return false;
            }
        }
        return false;
    }
};