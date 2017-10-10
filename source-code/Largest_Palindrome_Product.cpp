class Solution {
public:
    int largestPalindrome(int n) {
        if(n == 1) return 9;
        int Max = pow(10, n) - 1;
        for(int i = Max - 1; i > Max / 10; i--) {
            string left = to_string(i);
            string right = left;
            reverse(right.begin(), right.end());
            string s = left + right;
            long long N = atoll(s.c_str());
            for(long long x = Max; x * x >= N; x--) {
                if(N % x == 0) {
                    return N % 1337;
                }
            }
        }
        return 0;
    }
};