class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m > n) return 0;
        int result = 0;
        for(int i = 30; i >= 0; --i) {
            bool bitA = (bool) ((1 << i) & m);
            bool bitB = (bool) ((1 << i) & n);
            if(bitA != bitB) break;
            if(bitA) {
                result |= (1 << i);    
            }
        }
        return result;
    }
};