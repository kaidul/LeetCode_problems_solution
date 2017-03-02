class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n < 2) return n;
        bool exist[256] = {false};
        int start = 0, end = 0;
        int maxLen = 0;
        for(int end = 0; end < n; ++end) {
            if(exist[s[end]]) {
                maxLen = max(maxLen, end - start);
                while(s[start] != s[end]) {
                    exist[s[start++]] = false;
                }
                start++;
            } else {
                exist[s[end]] = true;    
            }
        }
        maxLen = max(maxLen, n - start);
        return maxLen;
    }
};