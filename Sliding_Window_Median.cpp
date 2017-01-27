class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
        vector<double> medians;
        medians.push_back((double(*mid) + *next(mid, k % 2 - 1)) / 2);
        for (int i=k; i < (int)nums.size(); i++) {
            window.insert(nums[i]);
            if(nums[i] < *mid) {
                mid--;
            }
            if(nums[i - k] <= *mid) {
                mid++;
            }
            window.erase(window.lower_bound(nums[i - k]));
            medians.push_back((double(*mid) + *next(mid, k % 2 - 1)) / 2);
        }
        
        return medians;
    }
};