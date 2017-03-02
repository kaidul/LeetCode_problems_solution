class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        for(long long i = 5; i <= INT_MAX and n / i > 0; i *= 5) {
            count += (n / i);
        }
        return count;
    }
};