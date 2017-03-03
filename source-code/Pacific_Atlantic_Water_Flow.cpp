class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool isValid(int x, int y, vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        return (x >= 0 and y >= 0 and x < n and y < m);
    }
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> result;
        int n = (int)matrix.size();
        if(n == 0) return result; 
        int m = (int)matrix[0].size();
        queue<pair<int, int>> Q;
        vector<vector<bool>> visited(n, vector<bool>(m , false));
        for(int i = 0; i < n; i++) {
            Q.push({i, 0});
            visited[i][0] = true;
        }
        for(int i = 1; i < m; i++) {
            Q.push({0, i});
            visited[0][i] = true;
        }
        while(!Q.empty()) {
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            for(int i = 0; i < 4; i++) {
                int X = x + dx[i];
                int Y = y + dy[i];
                if(isValid(X, Y, matrix) and !visited[X][Y] and matrix[X][Y] >= matrix[x][y]) {
                    visited[X][Y] = true;
                    Q.push({X, Y});
                }
            }
        }
        vector<vector<bool>> visited2(n, vector<bool>(m , false));
        assert(Q.empty());
        for(int i = 0; i < n; i++) {
            Q.push({i, m - 1});
            visited2[i][m - 1] = true;
        }
        for(int i = 0; i < m - 1; i++) {
            Q.push({n - 1, i});
            visited2[n - 1][i] = true;
        }
        while(!Q.empty()) {
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            if(visited[x][y]) {
                result.push_back({x, y});
            }
            for(int i = 0; i < 4; i++) {
                int X = x + dx[i];
                int Y = y + dy[i];
                if(isValid(X, Y, matrix) and !visited2[X][Y] and matrix[X][Y] >= matrix[x][y]) {
                    visited2[X][Y] = true;
                    Q.push({X, Y});
                }
            }
        }
        
        return result;
    }
};