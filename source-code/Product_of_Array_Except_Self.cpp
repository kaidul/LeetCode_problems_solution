class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int N = nums.size();
        vector<int> output;
        if(N < 1) return output;
        output.resize(N, 0);
        int prefixProd[N];
        int suffixProd[N];
        
        prefixProd[0] = nums[0];
        for(int i = 1; i < N; ++i) {
            prefixProd[i] = prefixProd[i - 1] * nums[i];
        }
        
        suffixProd[N - 1] = nums[N - 1];
        for(int i = N - 2; i >= 0; --i) {
            suffixProd[i] = suffixProd[i + 1] * nums[i];
        }
        
        for(int i = 0; i < N; ++i) {
            int prefix = (i > 0) ? prefixProd[i - 1] : 1;
            int suffix = (i < N - 1) ? suffixProd[i + 1] : 1;
            output[i] = prefix * suffix;
        }
        
        return output;
    }
};