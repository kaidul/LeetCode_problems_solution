// visualization of this logic: https://www.youtube.com/watch?v=cJayBq38VYw
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m <= 0) return 0;
        int n = heightMap[0].size();
        if (n <= 0) return 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (int i = 0; i < m; i++) {
            minHeap.push({heightMap[i][0], i * n});
            visited[i][0] = true;
            if (n - 1 > 0) {
                minHeap.push({heightMap[i][n - 1], i * n + n - 1});
                visited[i][n - 1] = true;
            }
        }

        for (int i = 0; i < n; i++) {
            minHeap.push({heightMap[0][i], i});
            visited[0][i] = true;
            if (m - 1 > 0) {
                minHeap.push({heightMap[m - 1][i], (m - 1) * n + i});
                visited[m - 1][i] = true;
            }
        }

        int totalWater = 0;
        int maxHeight = INT_MIN;
        
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        
        while (!minHeap.empty()) {
            pair<int, int> curr = minHeap.top();
            minHeap.pop();
            int currHeight = curr.first, x = curr.second / n, y = curr.second % n;
            maxHeight = max(maxHeight, currHeight);
            for (int i = 0; i < sizeof(dx) / sizeof(dx[0]); i++) {
                int neighX = x + dx[i];
                int neighY = y + dy[i];
                if (neighX < 0 or neighY < 0 or neighX >= m or neighY >= n or visited[neighX][neighY]) {
                    continue;
                }
                totalWater += max(maxHeight - heightMap[neighX][neighY], 0);
                minHeap.push({heightMap[neighX][neighY], neighX * n + neighY});
                visited[neighX][neighY] = true;
            }
        }

        return totalWater;
    }
};