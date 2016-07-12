class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = (int) nums.size();
        vector<int> result;
        if(n == 0) return result;
        result.resize(n);
        for(int i = 0; i < n; ++i) {
            result[i] = a * (nums[i] * nums[i]) + b * nums[i] + c;
        }
        sort(result.begin(), result.end());
        
        return result;
    }
};