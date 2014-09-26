class Solution {
public:
    double power(double x, int n) {
        if (n == 0) return 1;
        double half = power(x, n / 2);
        half *= half;
        if (n & 1) half *= x;
        return half;
    }

    double pow(double x, int n) {
        if (n < 0) return 1 / power(x, -n);
        return power(x, n);
    }
};