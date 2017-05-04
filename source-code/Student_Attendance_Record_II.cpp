// TLE
class Solution {
    const static int MOD = 1000000007;
    vector<int> fact;
    vector<int> ifact;
    
    int power(int base, int exp, int mod) {
        if(exp == 0) return 1;
        int ret = power(base, exp / 2, mod) % mod;
        ret = 1LL * ret * ret % mod;
        if(exp & 1) {
            ret = 1LL * ret * base % mod;
        }
        return ret;
    }
    
    int modInv(int base, int mod = MOD) {
        return power(base, mod - 2, mod);
    }
    
    void init(int n) {
        fact = vector<int>(n + 1, 0);
        ifact = vector<int>(n + 1, 0);
        fact[0] = ifact[0] = 1;
        for(int i = 1; i <= n; i++) {
            fact[i] = 1LL * i * fact[i - 1] % MOD;
            ifact[i] = modInv(fact[i]);
        }
    }
    
    int nCr(int n, int r) {
        if(r > n) return 0;
        int ans = fact[n];
        ans = 1LL * ans * ifact[r] % MOD;
        ans = 1LL * ans * ifact[n - r] % MOD;
        return ans;
    }
public:
    int checkRecord(int n) {
        init(n + 1);
        int maxLate = n - (n / 3);
        int result = 0;
        for(int i = 0; i <= maxLate; i++) {
            int ways = 0;
            for(int k = (i / 2) + (i % 2), pair = i / 2; k <= i; k++, pair--) {
                ways = (ways + (1LL * nCr(n - i + 1, k) * nCr(k, pair)) % MOD) % MOD;
            }
            result = (result + ways) % MOD;
            result = (result + (1LL * ways * (n - i) % MOD)) % MOD;
        }
        return result;
    }
};

// MLE
class Solution {
#define MOD 1000000007
    vector<vector<vector<int>>> dp;
    int n;
    
    int solve(int i, int k, int taken) {
        if(i == n) {
            return (k == 0);
        }
        if(dp[i][k][taken] != -1) {
            return dp[i][k][taken];
        }
        if(taken == 2) {
            return dp[i][k][taken] = solve(i + 1, k, 0) % MOD;
        }
        
        return dp[i][k][taken] = (solve(i + 1, k, 0) + (k > 0 ? solve(i + 1, k - 1, taken + 1) : 0)) % MOD;
    }
    
public:
    int checkRecord(int n) {
        this->n = n;
        int maxLate = n - (n / 3);
        dp= vector<vector<vector<int>>>(n, vector<vector<int>>(maxLate + 1, vector<int>(3, -1)));
        int result = 0;
        for(int i = 0; i <= maxLate; i++) {
            int cnt = solve(0, i, 0);
            result = (result + cnt) % MOD;
            result = (result + (1LL * cnt * (n - i) % MOD)) % MOD;
        }
        return result;
    }
};