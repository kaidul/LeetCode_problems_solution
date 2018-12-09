class Solution {
#define WATER pair<int, int>(-1, -1)
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    
    pair<int, int> find(int x, int y, vector<vector<pair<int, int>>>& parent) {
        if(parent[x][y] == WATER or parent[x][y] == pair<int, int>(x, y)) {
            return parent[x][y];
        }
        return parent[x][y] = find(parent[x][y].first, parent[x][y].second, parent);
    }
    
    void merge(int x, int y, int j, int k, int& nSet, vector<vector<pair<int, int>>>& parent) {
        pair<int, int> parL = find(x, y, parent);
        pair<int, int> parR = find(j, k, parent);
        if(parL != parR) {
            nSet--;
            parent[parL.first][parL.second] = parent[parR.first][parR.second];
        }
    }
    
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<vector<pair<int, int>>> parent(m, vector<pair<int, int>>(n, WATER));
        int nSet = 0;
        vector<int> result;
        for(int i = 0; i < positions.size(); ++i) {
            int x = positions[i].first;
            int y = positions[i].second;
            parent[x][y] = pair<int, int>(x, y);
            nSet++;
            
            for(int k = 0; k < 4; ++k) {
                int newX = x + dx[k];
                int newY = y + dy[k];
                if(newX >= 0 and newX < m and newY >= 0 and newY < n) {
                    if(find(newX, newY, parent) != WATER) {
                        merge(x, y, newX, newY, nSet, parent);
                    }
                }
            }
            result.push_back(nSet);
        }
        return result;
    }
};