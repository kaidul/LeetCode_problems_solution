class Solution {
public:
    string minWindow(string s, string t) {
        string result;
        int m = s.length();
        int n = t.length();
        if(n > m) return result;
        const int MAX = 256;
        int freq[MAX] = {0};
        int freq2[MAX] = {0};
        for(int i = 0; i < n; ++i) {
            freq2[t[i]]++;
        }
        int chars = 0;
        int minLen = INT_MAX;
        
        for(int left = 0, right = 0; right < m; ++right) {
            
            if(freq2[s[right]]) {
                freq[s[right]]++;
                if(freq[s[right]] == freq2[s[right]]) {
                    chars += freq2[s[right]];
                }
                
                if(chars == n) {
                    for(; left <= right; ++left) {
                        if(freq2[s[left]]) {
                            if(freq[s[left]] == freq2[s[left]]) {
                                int len = right - left + 1;
                                if(len < minLen) {
                                    minLen = len;
                                    result = s.substr(left, len);
                                }
                                chars -= freq2[s[left]];
                                freq[s[left]]--;
                                left++;
                                break;
                            } else if(freq[s[left]] > freq2[s[left]]) {
                                freq[s[left]]--;
                            }    
                        }
                    }
                }
                
            }
        }
        return result;
    }
};