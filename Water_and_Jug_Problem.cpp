class Solution {
    int gcd(int x, int y) {
        return (y > 0) ? gcd(y, x % y) : x;
    }
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z > x + y) return false;
        if(x == 0 or y == 0) return (z == x or z == y);
        return (z % gcd(x, y) == 0);
    }
};