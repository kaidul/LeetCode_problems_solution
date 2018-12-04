class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int rows = (int) A.size();
        int cols = (int) A[0].size();
        for (int i = 0; i < rows; i++) {
            int left = 0, right = cols - 1;
            while (left <= right) {
                swap(A[i][left], A[i][right]);
                A[i][left] ^= 1;
                if(left < right) {
                    A[i][right] ^= 1;    
                }
                left++, right--;
            }
        }
        
        return A;
    }
};