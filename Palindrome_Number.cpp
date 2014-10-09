class Solution {
public:
    void isPalindrome(int x, int &y, bool &result) {
        if(!result or x == 0) return;
        int a = x % 10;
        isPalindrome(x / 10, y, result);
        if(!result) return;
        int b = y % 10;
        if(a != b) result = false;
        y /= 10;
    }

    bool isPalindrome(int x) {
        if(x < 0) return false;
        bool result = true;
        int y = x;
        isPalindrome(x, y, result);
        return result;
    }
};