class Solution {
    bool isVowel(char ch) {
        return (ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u') or
                (ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U');
    }
public:
    string reverseVowels(string s) {
        for(int n = (int)s.length(), left = 0, right = n - 1; left < right; ) {
            if(isVowel(s[left]) and isVowel(s[right])) {
                swap(s[left], s[right]);
                left++; right--;
            } else {
                if(!isVowel(s[left])) {
                    left++;
                }
                if(!isVowel(s[right])) {
                    right--;
                }
            }
        }
        return s;
    }
};