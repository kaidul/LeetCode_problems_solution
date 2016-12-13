class Solution {
    
    int longestSubstring(int left, int right, string& s, int k) {
        if(left >= right) {
            return 0;
        }
        if(right - left < k) {
            return 0;
        }
        int count[26] = {0};
        for(int i = left; i < right; i++) {
            count[s[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(count[i] == 0) {
                continue;
            }
            if(count[i] < k) {
                for(int j = left; j < right; j++) {
                    if(s[j] - 'a' == i) {
                        return max( longestSubstring(left, j, s, k), 
                            longestSubstring(j + 1, right, s, k) );       
                    }
                }
            }
        }
        return right - left;
    }
    
public:
    int longestSubstring(string s, int k) {
        return longestSubstring(0, s.length(), s, k);
    }
};