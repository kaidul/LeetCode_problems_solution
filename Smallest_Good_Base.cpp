class Solution {
    unsigned long long solve(unsigned long long n, int d) {
        unsigned long long right = (unsigned long long)(pow(n, 1.0 / d) + 1);
        unsigned long long left = 1ull;
        while(left <= right) {
            unsigned long long mid = left + (right - left) / 2;
            unsigned long long num = 1ull, base = 1ull;
            for(int i = 0; i < d; i++) {
                base *= mid;
                num += base;
            }
            if(num == n) {
                return mid;
            }
            if(num < n) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1ull;
    } 
public:
    string smallestGoodBase(string n) {
        unsigned long long ulln = (unsigned long long)stoll(n);
        for(int i = 62; i >= 1; i--) {
            if((1ull << i) < ulln) {
                unsigned long long curr = solve(ulln, i);
                if(curr != -1) {
                    return to_string(curr);
                }
            }
        }
        return to_string(ulln - 1);
    }
};