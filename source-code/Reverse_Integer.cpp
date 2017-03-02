class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while(x) {
            result = result * 10 + (x % 10);
            x /= 10;
        }
        return result;
    }
};