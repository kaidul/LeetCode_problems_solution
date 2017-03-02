class Solution {
public:
    int bulbSwitch(int n) {
        /* TLE
        if(n == 0) return n;
        int pressed[n] = {1};
        for(int i = 2; i < n; ++i) {
            for(int k = i; k <= n; k += i) {
                pressed[k - 1]++;
            }
        }
        if(n > 1) pressed[n - 1]++;
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(pressed[i] & 1) {
                ++cnt;
            }
        }
        return cnt;
        */
        
        return sqrt(n);
    }
};