class Solution {
public:
    int smallestFactorization(int a) {
        if(a < 10) { return a; }
        int factors[40];
        int i = 0;
        for(int d = 9; d > 1; d--) {
            while(a % d == 0) {
                a /= d;
                factors[i++] = d;
            }
        }
        if(a > 10) {
            return 0;
        }
        long long result = 0LL;
        for(int k = i - 1; k >= 0; k--) {
            result = result * 10 + factors[k];
            if(result > INT_MAX) { return 0; }
        }
        return (int)result;
    }
};