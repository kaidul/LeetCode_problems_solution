class Solution {
public:
    int integerBreak(int n) {
        int product = 1;
        for(int i = 2; i <= 3; ++i) {
            int quotient = n / i;
            int mod = n % i;
            int multiply = pow(i, quotient - 1);
            product = max(product, (mod > 1 or quotient < 2) ? (multiply * i * mod) : (multiply * (i + mod)) );
        }
        return product;
    }
};