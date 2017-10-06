class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    int bfs(int x, int y, int nextX, int nextY, vector<vector<int>>& forest, vector<vector<bool>>& visited) {
        int n = (int) forest.size();
        int m = (int)forest[0].size();
        queue<pair<pair<int, int>, int>> Q;
        Q.push({{x, y}, 0});
        visited[x][y] = true;
        while(!Q.empty()) {
            pair<pair<int, int>, int>& front = Q.front();
            int currX = front.first.first;
            int currY = front.first.second;
            int d = front.second;
            if(currX == nextX and currY == nextY) {
                return d;
            }
            for(int i = 0; i < 4; i++) {
                int newX = currX + dx[i];
                int newY = currY + dy[i];
                if(newX >= 0 and newY >= 0 and newX < n and newY < m and forest[newX][newY] > 0 and !visited[newX][newY]) {
                    visited[newX][newY] = true;
                    Q.push({{newX, newY}, d + 1});
                } 
            }
            Q.pop();
        }
        return -1;
    }
    
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int n = (int)forest.size();
        int m = (int)forest[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pQ;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(forest[i][j] > 1) {
                    pQ.push({forest[i][j], {i, j}});
                }
            }
        }
        int x = 0, y = 0;
        int minSteps = 0;
        while(!pQ.empty()) {
            pair<int, pair<int, int>> top = pQ.top();
            int treeHeight = top.first;
            int nextX = top.second.first;
            int nextY = top.second.second;
            pQ.pop();
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            int distance = bfs(x, y, nextX, nextY, forest, visited);
            if(distance == -1) {
                return distance;
            }
            minSteps += distance;
            x = nextX, y = nextY;
        }
        
        return minSteps;
    }
};