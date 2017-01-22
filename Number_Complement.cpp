class Solution {
public:
    int findComplement(int n) {
        int complement = 0;
        int msb = log((double) n) / log(2.0);
        for(int bit = 0; bit <= msb; bit++) {
            if(n & (1 << bit)) {
                complement &= ~(1 << bit);
            } else {
                complement |= (1 << bit);
            }
        }
        return complement;
    }
};