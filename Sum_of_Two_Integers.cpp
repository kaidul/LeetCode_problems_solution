class Solution {
public:
    int getSum(int a, int b) {
        int Xor = a ^ b;
        int And = a & b;
        while(And) {
            int tmp = Xor;
            Xor ^= (And << 1);
            And = tmp & (And << 1);
        }
        return Xor;
    }
};