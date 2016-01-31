class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;
        sign = (dividend < 0) ? -sign : sign;
        sign = (divisor < 0) ? -sign : sign;

        unsigned long long i64Dividend = abs((long long)dividend);
        unsigned long long i64Divisor = abs((long long)divisor);
        unsigned long long i64Divisor2 = i64Divisor;

        unsigned long cnt = 1;
        while (i64Dividend > i64Divisor) {
            i64Divisor = i64Divisor << 1;
            cnt = cnt << 1;
        }

        int res = 0;
        while (i64Dividend >= i64Divisor2) {
            while (i64Dividend >= i64Divisor) {
                i64Dividend -= i64Divisor;
                res += cnt;
            }
            i64Divisor = i64Divisor >> 1;
            cnt = cnt >> 1;
        }

        return (sign < 0) ? -res : res;
    }
};