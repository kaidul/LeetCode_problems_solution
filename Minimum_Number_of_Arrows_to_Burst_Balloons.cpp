class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.empty()) return 0;
        sort(points.begin(), points.end());
        int n = points.size();
        int balloons = 0;
        for(int i = 0; i < n; ++i) {
            int boundary = points[i].second;
            while(i + 1 < n and points[i + 1].first <= boundary) {
                boundary = min(boundary, points[i + 1].second);
                ++i;
            }
            balloons++;
        }
        
        return balloons;
    }
};