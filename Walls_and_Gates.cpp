class Solution {
    
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    bool isValid(int x, int y, vector<vector<bool>> const& visited, vector<vector<int>> const& rooms) {
        return (x >= 0 and y >= 0 and x < (int)rooms.size() and y < (int)rooms[0].size() and !visited[x][y] and rooms[x][y] != -1);
    }
    
    bool isValid2(int x, int y, int distance, vector<vector<int>> const& rooms) {
        return (x >= 0 and y >= 0 and x < (int)rooms.size() and y < (int)rooms[0].size() and rooms[x][y] > distance);
    }

    void wallsAndGatesRecur(int x, int y, vector<vector<bool>>& visited, vector<vector<int>>& rooms, int distance = 0) {
        if(rooms[x][y] < distance) return;
        rooms[x][y] = distance;
        
        visited[x][y] = true;
        for(int i = 0, n = sizeof(dx) / sizeof(dx[0]); i < n; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(isValid(newX, newY, visited, rooms)) {
                wallsAndGatesRecur(newX, newY, visited, rooms, distance + 1);
            }
        }
        visited[x][y] = false;
    }
    
    void wallsAndGatesBfs(int x, int y, vector<vector<int>>& rooms, int distance = 0) {
        queue<pair<int, int>> Q;
        vector<vector<bool>> visited((int)rooms.size(), vector<bool>((int)rooms[0].size(), false));
        Q.push(make_pair(x, y));
        visited[x][y] = true;
        
        while(!Q.empty()) {
            x = Q.front().first;
            y = Q.front().second;
            Q.pop();
            for(int i = 0, n = sizeof(dx) / sizeof(dx[0]); i < n; ++i) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(isValid(newX, newY, visited, rooms)) {
                    if(rooms[newX][newY] > rooms[x][y] + 1) {
                        rooms[newX][newY] = rooms[x][y] + 1;
                        visited[newX][newY] = true;
                        Q.push(make_pair(newX, newY));
                    }
                }
            }
        } // end of while
        
    }
    
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size();
        if(n == 0) return;
        int m = rooms[0].size();
        if(m == 0) return;
        queue <pair<int, int>> Q;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(!rooms[i][j]) { // gate
                    // dfs TLE
                    // vector<vector<bool>> visited(n, vector<bool>(m, false));
                    // wallsAndGatesRecur(i, j, visited, rooms);
                    
                    // bfs TLE
                    // wallsAndGatesBfs(i, j, rooms);
                    
                    Q.push(make_pair(i, j));
                }
            }
        }
        
        // pruned bfs
        while(!Q.empty()) {
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
            for(int i = 0, n = sizeof(dx) / sizeof(dx[0]); i < n; ++i) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                int newDistance = rooms[x][y] + 1;
                if(isValid2(newX, newY, newDistance, rooms)) {
                    rooms[newX][newY] = newDistance;
                    Q.push(make_pair(newX, newY));
                }
            }
        }
    }
};