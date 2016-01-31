class Solution {
public:
    bool canPermutePalindrome(string s) {
#define MAX 256
        vector<int> freq(MAX, 0);
        for(int i = 0; i < s.length(); ++i) {
            freq[s[i]]++;
        }
        int odd = 0;
        for(int i = 0; i < MAX; ++i) {
            odd += (freq[i] & 1);
        }
        int len = s.length();
        if(len & 1) {
            return odd == 1;
        }
        return odd == 0;
    }
};