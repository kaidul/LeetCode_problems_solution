class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for(int i = 0, j = 31; i < j; i++, j--) {
            bool iSet = (bool)(n & (1 << i));
            bool jSet = (bool)(n & (1 << j));
            n &= ~(1 << j);
            n &= ~(1 << i);
            if(iSet) n |= (1 << j);
            if(jSet) n |= (1 << i);
        }
        return n;
    }
};