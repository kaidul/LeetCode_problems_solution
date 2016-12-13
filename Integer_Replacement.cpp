class Solution {
public:
    int integerReplacement(int n) {
        if(1 == n) return 0;
        return  1 + ((n & 1) ? 1 + min( integerReplacement(n >> 1), integerReplacement((n >> 1) + 1) ) : integerReplacement(n >> 1));
    }
};


// Memorization
class Solution {
    int integerReplacement(int n, unordered_map<int, int>& dp) {
        if(1 == n) return 0;
        if(dp.find(n) != dp.end()) return dp[n];
        return dp[n] = 1 + ((n & 1) ? 1 + min( integerReplacement(n >> 1, dp), integerReplacement((n >> 1) + 1, dp) ) : integerReplacement(n >> 1, dp));
    }
public:
    int integerReplacement(int n) {
        unordered_map<int, int> dp;
        return integerReplacement(n, dp);
    }
};


// Bit manipulation
class Solution {
public:
    int integerReplacement(int n) {
        if(n <= 3) return (n - 1);
        if(n & 1) {
            return 2 + (__builtin_popcount(n >> 1) < __builtin_popcount((n >> 1) + 1) ? integerReplacement(n >> 1) : integerReplacement((n >> 1) + 1));
        }
        return 1 + integerReplacement(n >> 1);
    }
};