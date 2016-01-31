class Solution {
public:
    int maxSubArray(int A[], int n) {
        int result = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum = max(sum + A[i], A[i]);
            
            result = max(sum, result);
        }
        return result;
    }
};