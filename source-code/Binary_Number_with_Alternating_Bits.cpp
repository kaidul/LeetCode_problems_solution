class Solution {
public:
    bool hasAlternatingBits(int n) {
        int length = log((double) n) / log(2.0);
        int on = 1;
        for(int i = length; i >= 0; i--) {
            if(on) {
                if(!(n & (1 << i))) {
                    return false;
                }
            } else {
                if(n & (1 << i)) {
                    return false;
                }
            }
            on ^= 1;
        }
        return true;
    }
};