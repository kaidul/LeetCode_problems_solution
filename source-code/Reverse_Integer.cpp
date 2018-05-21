class Solution {
public:
    int reverse(int x) {
        long long result = 0LL;
        while(x) {
            result = result * 10 + (x % 10);
            if(result > INT_MAX or result < INT_MIN) {
                return 0;
            }
            x /= 10;
        }
        return (int) result;
    }
};