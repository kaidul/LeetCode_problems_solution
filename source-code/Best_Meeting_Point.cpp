class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int result = 0;
        int n = grid.size();
        if(n == 0) return result;
        int m = grid[0].size();
        vector<int> xCords, yCords;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j]) {
                    xCords.push_back(i);
                    yCords.push_back(j);
                }
            }
        }
        sort(yCords.begin(), yCords.end());
        int mid = (int) xCords.size() / 2;
        int midX = xCords[mid];
        int midY = yCords[mid];
        for(int i = 0; i < xCords.size(); ++i) {
            result += abs(midX - xCords[i]);
            result += abs(midY - yCords[i]);
        }
        return result;
    }
};