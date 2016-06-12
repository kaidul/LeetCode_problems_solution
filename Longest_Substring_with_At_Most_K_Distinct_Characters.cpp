class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int maxLen = 0;
        int cnt = 0;
        int n = (int) s.length();
        vector<int> freq(255, 0);
        for(int left = 0, right = 0; right < n; ++right) {
            if(freq[s[right]] == 0) {
                cnt++;
                while(cnt > k and left <= right) {
                    freq[s[left]]--;
                    if(freq[s[left]] == 0) {
                        cnt--;
                    }
                    ++left;
                }
            }
            freq[s[right]]++;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};