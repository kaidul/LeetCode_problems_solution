class Solution {
public:
    int maxRotateFunction(vector<int>& arr) {
        int n = (int)arr.size(), F = 0, sum = 0;
        for(int i = 0; i < n; ++i) {
            F += (arr[i] * i);
            sum += arr[i];
        }
        int result = F;
        for(int i = n - 1; i >= 0; --i) {
            F = F + sum - n * arr[i];
            result = max(result, F);
        }
        return result;
    }
};