class Solution {
public:
    vector<int> pSum;
    int total = 0;
    mt19937 rng{random_device{}()};
    uniform_int_distribution<int> uni;
    Solution(vector<int> w) {
        for (int weight : w) {
            total += weight;
            pSum.push_back(total);
        }
        uni = uniform_int_distribution<int>{0, total - 1};
    }

    int pickIndex() {
        int target = uni(rng);
        int low = 0, high = (int)pSum.size() - 1;
        int lowerBound = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (target >= pSum[mid]) {
                low = mid + 1;
            } else {
                lowerBound = mid;
                high = mid - 1;
            }
        }
        return lowerBound;
    }

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */