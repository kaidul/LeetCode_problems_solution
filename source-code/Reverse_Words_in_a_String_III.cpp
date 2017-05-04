class Solution {
public:
    string reverseWords(string s) {
        int i = 0, left = 0;
        int n = (int)s.length();
        while(i < n) {
            if(s[i] == ' ' or s[i] == '\n') {
                reverse(s.begin() + left, s.begin() + i);
                left = i + 1;
            }
            i++;
        }
        reverse(s.begin() + left, s.end());
        return s;
    }
};