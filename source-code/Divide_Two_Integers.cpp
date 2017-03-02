class Solution {
public:
    int divide(int dividend, int divisor) {
        long long i64Dividend = dividend, i64Divisor = divisor;
        int sign = i64Dividend < 0 ^ i64Divisor < 0 ? -1 : 1;
        i64Dividend = abs(i64Dividend);
        i64Divisor = abs(i64Divisor);
        long long q = 0;
        for (long long sum = 0, i = 31; i >= 0; i--) {
            if (sum + (i64Divisor << i) <= i64Dividend) {
                sum += i64Divisor << i;
                q |= 1LL << i;
            }
        }
        if (sign < 0) q = -q;
        return q >= INT_MAX || q < INT_MIN ? INT_MAX : q;
    }
};