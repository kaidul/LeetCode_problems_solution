class Solution {
public:
    int findMaxLength(vector<int>& arr) {
        unordered_map<int, int> dp;
        int one = 0, zero = 0;
        dp[0] = -1;
        int result = 0;
        for(int i = 0; i < (int)arr.size(); i++) {
            one += arr[i];
            zero += !arr[i];
            if(dp.count(one - zero)) {
                result = max(result, i - dp[one - zero]);
            } else {
                dp[one - zero] = i;
            }
        }
        
        return result;
    }
};