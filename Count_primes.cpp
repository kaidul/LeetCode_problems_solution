class Solution {
public:
    int countPrimes(int n) {
        if(n < 3) return 0;
        bool primes[n + 1];
        for(int i = 0; i < n; i++) primes[i] = true; 
        int sqrtN = sqrt(n);
        for(int i = 3; i <= sqrtN; i += 2) {
            if(primes[i]) {
                for(int k = i * i; k < n; k += (i << 1)) {
                    primes[k] = false;
                }
            }
        }
        int cnt = 1; // 2
        for(int i = 3; i < n; i += 2) {
            if(primes[i]) cnt++;
        }
        return cnt;
    }
};