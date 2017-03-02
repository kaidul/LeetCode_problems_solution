class Solution {
    set<pair<int, int>> pointMap;
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if(points.empty()) return true;
        int center = 0, n = (int)points.size();
        for(int i = 0; i < n; ++i) {
            pointMap.insert(points[i]);
            center += points[i].first;
        }
        center /= n;
        for(int i = 0; i < n; ++i) {
            if(pointMap.find({(center << 1) - points[i].first, points[i].second}) == pointMap.end()) {
                return false;
            }
        }
        return true;
    }
};