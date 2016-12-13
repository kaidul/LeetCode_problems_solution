class Solution {
public:
    int findNthDigit(int n) {
        // total[i] denotes the total integers of i digits
        int total[10] = {0, 9, 90, 900, 9000, 90000, 900000, 9000000, 90000000, 900000000};
        int digit = 1;
        for(int i = 1; total[i] * digit > 0 and total[i] * digit < n; ++i, ++digit) {
            n -= (total[i] * digit);
        }
        int q = n / digit;
        int value = total[digit] / 9; // first integer holding i digits
        while(--q > 0) ++value;
        if(n % digit != 0) {
            ++value;
            string seq = to_string(value);
            return (int)(seq[n % digit - 1] - '0');
        }
        return value % 10;
    }
};