class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = (int)nums.size();
        if(n <= 1) return;
        
        vector<int> bucket[n];
        int Min = INT_MAX, Max = INT_MIN;
        for(int i = 0; i < n; ++i) {
            Max = max(Max, nums[i]);
            Min = min(Min, nums[i]);
        }
        int range = Max - Min;
        for(int i = 0; i < n; ++i) {
            int indx = 1.0 * (nums[i] - Min) / range * (n - 1);
            bucket[indx].push_back(nums[i]);
        }
        int j = 0;
        vector<int> output(n);
        for(int i = 0; i < n; ++i) {
            sort(bucket[i].begin(), bucket[i].end());
            for(int k = 0; k < (int)bucket[i].size(); ++k) {
                output[j++] = bucket[i][k];    
            }
        }
        int k = n - 1;
        for(int i = 1; i < n; i += 2) {
            nums[i] = output[k--];
        }
        for(int i = 0; i < n; i += 2) {
            nums[i] = output[k--];
        }
    }
};