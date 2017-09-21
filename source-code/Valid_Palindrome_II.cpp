class Solution {
    bool isPalindrome(string s, int left, int right) {
        while(left < right) {
            if(s[left] != s[right]) {
                return false;
            }
            ++left, --right;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while(left <= right and s[left] == s[right]) {
            ++left, --right;
        }
        if(left >= right) {
            return true;
        }
        return isPalindrome(s, left + 1, right) or isPalindrome(s, left, right - 1);
    }
};