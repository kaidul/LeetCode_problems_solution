class Solution {
public:
    /*
    // recursive solution
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
    */
    bool isPalindrome(int x) {
        int reverseX = 0;
        int X = x;
        while(x) {
            reverseX = reverseX * 10 + x % 10;
            x /= 10;
        }
        return X == reverseX and 
               X >= 0; // if the number is negative, its not palindrome
    }
};