class Solution {
public:
    int arrangeCoins(int n) {
        return (int)floor((long long)(floor(sqrt(1LL + 8LL * n)) - 1LL) >> 1LL);
    }
};