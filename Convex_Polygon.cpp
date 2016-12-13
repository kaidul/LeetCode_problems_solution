class Solution {
    // calculate determinant of 2*2 matrix A
    long det(vector<vector<int>>& A) { 
        return A[0][0] * A[1][1] - A[0][1] * A[1][0];
    }
    
public:
    bool isConvex(vector<vector<int>>& p) {
        long prev = 0;
        for (int i = 0, n = p.size(); i < n; ++i) {
            vector<vector<int>> A;
            for (int j = 1; j < 3; ++j) {
                A.push_back({p[(i + j) % n][0] - p[i][0], p[(i + j) % n][1] - p[i][1]});
            }
            long curr = det(A);
            if(curr * prev < 0) {
                return false;
            }
            if(curr) {
                prev = curr;    
            }
        }
        return true;
    }
};