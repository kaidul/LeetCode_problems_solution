class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // O((n - k) * k) TLE
        /**
        int n = nums.size();
        for(int i = 0; i < n - 1; ++i) {
            int X = nums[i];
            int offset = i + 1;
            for(int j = offset; j <= min(offset + k, n - 1); ++j) {
                int Y = nums[offset + j];
                if(abs(X - Y) <= t) {
                    return true;
                }
            }
        }
        return false;
        **/
        // O(nlogk)
        int n = nums.size();
        if(k >= n) {
            k = n - 1;
        }
        if(k <= 0) return false;
        multiset<long long> window;
        for(int i = 0; i <= k; ++i) {
            window.insert(nums[i]);
        }
        auto prev = window.begin();
        auto curr = ++window.begin();
        while(curr != window.end()) {
            if(*curr - *prev <= t) {
                return true;
            }
            prev = curr;
            ++curr;
        }
        for(int i = k + 1; i < n; ++i) {
            window.erase(window.find(nums[i - k - 1]));
            int curr = nums[i];
            if(window.find(curr) != window.end()) {
                return true;
            }
            auto upperBound = window.upper_bound(curr);
            if(upperBound != window.end() and *upperBound - curr <= t) {
                return true;
            }
            if(upperBound != window.begin()) {
                --upperBound;
                if(curr - *upperBound <= t) {
                    return true;
                }
            }
            window.insert(curr);
        }
        return false;
    }
};