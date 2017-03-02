class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n);
        ugly[0] = 1;
        int m = (int)primes.size();
        vector<int> indx(m, 0);
        vector<int> factors(primes.begin(), primes.end());
        for(int i = 1; i < n; ++i) {
            int nextUgly = factors[0];
            for(int k = 1; k < m; ++k) {
                nextUgly = min(nextUgly, factors[k]);
            }
            ugly[i] = nextUgly;
            for(int k = 0; k < m; ++k) {
                if(nextUgly == factors[k]) {
                    indx[k]++;
                    factors[k] = ugly[indx[k]] * primes[k];
                }
            }
        }
        return ugly[n - 1];
    }
};