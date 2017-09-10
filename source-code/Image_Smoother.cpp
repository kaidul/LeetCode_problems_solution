class Solution {
    const int Dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
    const int Dy[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};
    
    inline bool isValid(int x, int y, vector<vector<int>>& M) {
        return x >= 0 and y >= 0 and x < M.size() and y < M[0].size();
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = (int)M.size();
        int n = (int)M[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int neighs = 0;
                int weight = 0;
                for(int k = 0; k < sizeof(Dx) / sizeof(Dx[0]); k++) {
                    int x = i + Dx[k], y = j + Dy[k];
                    if(isValid(x, y, M)) {
                        neighs++;
                        weight += M[x][y];
                    }
                }
                result[i][j] = weight / neighs;
            }
        }
        return result;
    }
};