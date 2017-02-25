class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = (int)nums.size();
        vector<pair<int, int>> arr;
        for(int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }
        sort(arr.begin(), arr.end(), greater<pair<int, int>>());
        vector<string> result(n);
        if(arr.size() > 0) {
            int pos = arr[0].second;
            result[pos] = "Gold Medal";
        }
        if(arr.size() > 1) {
            int pos = arr[1].second;
            result[pos] = "Silver Medal";
        }
        if(arr.size() > 2) {
            int pos = arr[2].second;
            result[pos] = "Bronze Medal";
        }
        for(int i = 3; i < n; i++) {
            int pos = arr[i].second;
            result[pos] = to_string(i + 1);
        }
        
        return result;
    }
};