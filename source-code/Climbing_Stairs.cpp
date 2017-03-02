class Solution {
public:
    // Exhaustive search - TLE
    int climbStairs(int step, int n) {
        if(n < 0) return 0;
        if(n == 0) return 1;
        return climbStairs(1, n - 1) + climbStairs(2, n - 2);
    }
    int climbStairs(int n) {
        // return climbStairs(1, n - 1) + climbStairs(2, n - 2);
        
        // basically a fibonacci
        if(n < 4) return n;
        int f0 = 2, f1 = 3;
        for(int i = 4; i <= n; ++i) {
            int tmp = f1;
            f1 += f0;
            f0 = tmp;
        }
        return f1;
    }
};