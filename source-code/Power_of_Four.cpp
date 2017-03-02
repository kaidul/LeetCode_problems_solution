class Solution {
public:
    bool isPowerOfFour(int num) {
        return (!(num & (num - 1)) and (num & 0x55555555));

        // if(num == 1) return true;
        // return ((num & (num - 1)) == 0 and (num % 10 == 6 or num % 10 == 4));
    }
};