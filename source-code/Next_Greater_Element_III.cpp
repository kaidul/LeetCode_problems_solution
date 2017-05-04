class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int m = (int)s.length();
        int k = m - 1;
        for(int i = m - 1; i > 0; i--) {
           if(s[i - 1] < s[i]) {
               k = i - 1;
               break;
           }
        }
        for(int i = m - 1; i > k; i--) {
            if(s[i] > s[k]) {
                swap(s[i], s[k]);
                break;
            }
        }
        reverse(s.begin() + k + 1, s.end());
        
        long long result = 0LL;
        for(int i = 0; i < m; i++) {
            int digit = s[i] - '0';
            result *= 10;
            result += digit;
        }
        if((int)result == n or result < INT_MIN or result > INT_MAX) {
            return -1;
        }
        return (int)result;
    }
};