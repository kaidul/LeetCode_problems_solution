class Solution {
public:
    /*
    int numberOfArithmeticSlices(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return 0;
        vector<int> interval(n - 1);
        for(int i = 0; i < n - 1; ++i) {
            interval[i] = arr[i + 1] - arr[i];
        }
        int result = 0;
        for(int i = 0; i < n - 1; ++i) {
            int len = 1;
            while(i + 1 < n - 1 and interval[i] == interval[i + 1]) {
                ++i;
                len++;
            }
            int elem = len + 1;
            result += ((elem - 2) * (elem - 1)) / 2;
        }
        return result;
    }
    */
    int numberOfArithmeticSlices(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return 0;
        vector<int> dp(n, 0);
        if(arr[2] - arr[1] == arr[1] - arr[0]) {
            dp[2] = 1;
        }
        int result = dp[2];
        for(int i = 3; i < n; ++i) {
            if(arr[i] - arr[i - 1] == arr[i - 1] - arr[i - 2]) {
                dp[i] = dp[i - 1] + 1;
            }
            result += dp[i];
        }
        return result;
    }
};