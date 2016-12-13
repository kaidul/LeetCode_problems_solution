class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int minRadius = 0;
        for(int i = 0; i < houses.size(); i++) {
            int currRadius = INT_MAX;
            auto lbound = lower_bound(heaters.begin(), heaters.end(), houses[i]);
            if(lbound != heaters.end()) {
                currRadius = *lbound - houses[i];
            }
            if(lbound != heaters.begin()) {
                int prev = *(--lbound);
                currRadius = min(currRadius, houses[i] - prev);
            }
            minRadius = max(minRadius, currRadius);
        }
        
        return minRadius;
    }
};