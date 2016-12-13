class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = points.size();
        if(n < 3) {
            return 0;
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            unordered_map<int, int> freq;
            for(int j = 0; j < n; ++j) {
                if(i == j) continue;
                int dx = points[i].first - points[j].first;
                int dy = points[i].second - points[j].second;
                int dis = dx * dx + dy * dy;
                freq[dis]++;
            }
            for(auto const& dis: freq) {
                int f = dis.second;
                if(f >= 2) {
                    cnt += (f * (f - 1));
                }
            }
        }
        return cnt;
    }
};