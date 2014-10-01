class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;
        sign = (dividend < 0) ? -sign : sign;
        sign = (divisor < 0) ? -sign : sign;

        unsigned long long tmp = abs((long long)dividend);
        unsigned long long tmp2 = abs((long long)divisor);

        unsigned long c = 1;
        while (tmp > tmp2) {
            tmp2 = tmp2 << 1;
            c = c << 1;
        }

        int res = 0;
        while (tmp >= abs((long long)divisor)) {
            while (tmp >= tmp2) {
                tmp -= tmp2;
                res += c;
            }
            tmp2 = tmp2 >> 1;
            c = c >> 1;
        }

        return (sign < 0) ? -res : res;
    }
};