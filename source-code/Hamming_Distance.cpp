class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = 0;
        for(int i = 0; i < 31; i++) {
            diff += ((x & (1 << i)) != (y & (1 << i)));
        }
        return diff;
    }
};