class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = (int)wall.size();
        int crossed = n;
        int passed = 0;
        unordered_map<int, int> end;
        for(int i = 0; i < n; i++) {
            int m = (int)wall[i].size();
            int right = 0;
            for(int j = 0; j < m - 1; j++) {
                right += wall[i][j];
                end[right]++;
                passed = max(passed, end[right]);
            }
        }
        crossed -= passed;
        return crossed;
    }
};