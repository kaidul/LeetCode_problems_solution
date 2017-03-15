class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map <char, int> freq;
        int distinct = 0, result = 0;
        for(int start = 0, end = 0; end < s.length(); ++end) {
            if(freq[s[end]]) {
                freq[s[end]]++;
            } else {
                freq[s[end]] = 1;
                distinct++;
                if(distinct > 2) {
                    for(int k = start; k < end; ++k) {
                        freq[s[k]]--;
                        if(!freq[s[k]]) {
                            --distinct;
                            start = k + 1;
                            break;
                        }
                    }
                }
            }
            result = max(result, end - start + 1);
        }
        return result;
    }
};