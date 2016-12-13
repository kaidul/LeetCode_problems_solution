class Solution {
public:
    int longestPalindrome(string s) {
        if(s.empty()) return 0;
        int freq[256] = {0};
        for(int i = 0; i < (int)s.length(); ++i) {
            freq[s[i]]++;
        }
        int length = 0, odd = 0;
        for(int i = 0; i < 256; ++i) {
            odd += (freq[i] & 1);
            length += freq[i];
        }
        length -= odd;
        length += (odd > 0);
        
        return length;
    }
};