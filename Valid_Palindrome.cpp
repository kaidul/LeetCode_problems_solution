class Solution {
public:
    bool isAlphanumericCharacter(char c) {
        return (c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z') or (c >='0' and c <= '9');
    }
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        string Reverse = "", actual;
        for(int i = 0, n = s.length(); i < n; ++i) {
            if(isAlphanumericCharacter(s[i])) {
                Reverse += s[i];
            }
        }
        if(Reverse.empty()) return true;
        transform(Reverse.begin(), Reverse.end(), Reverse.begin(), ::tolower);
        actual = Reverse;
        reverse(Reverse.begin(), Reverse.end());
        return actual == Reverse;
    }
};