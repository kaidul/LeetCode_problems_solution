class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        int m = (int)matrix[0].size();
        queue<pair<int, int>> Q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j]) {
                    matrix[i][j] = INT_MAX;
                } else {
                    Q.push({i, j});
                }
            }
        }
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        while(!Q.empty()) {
            int x = Q.front().first, y = Q.front().second;
            Q.pop();
            for(int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX >= 0 and newX < n and newY >= 0 and newY < m and matrix[x][y] + 1 < matrix[newX][newY]) {
                    matrix[newX][newY] = matrix[x][y] + 1;
                    Q.push({newX, newY});
                }
            }
        }
        
        return matrix;
    }
};