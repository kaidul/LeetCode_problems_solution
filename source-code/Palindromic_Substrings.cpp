class Solution {
    int expandAroundCenter(int left, int right, string const& s) {
        if(left < 0) { return 0; }
        int count = 0;
        while(left >= 0 and right < s.length() and s[left] == s[right]) {
            ++count;
            --left, ++right;
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        int result = 0;
        for(int i = 0; i < s.length(); i++) {
            result += expandAroundCenter(i, i, s);
            result += expandAroundCenter(i - 1, i, s);
        }
        return result;
    }
};