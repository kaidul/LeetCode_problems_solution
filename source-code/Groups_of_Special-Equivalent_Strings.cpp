class Solution {
    bool isSpecialEquivalent(string const& s, string const& t) {
        int freqOdd[26] = {0}, freqEven[26] = {0};
        for(int i = 0; i < s.length(); i++) {
            if(i & 1) {
                freqEven[s[i] - 'a']++;
                freqEven[t[i] - 'a']--; 
            } else {
                freqOdd[s[i] - 'a']++;
                freqOdd[t[i] - 'a']--;
            }
        }
        for(int i = 0; i < 26; i++) {
            if(freqEven[i] < 0 or freqOdd[i] < 0) return false;
        }
        return true;
    }
public:
    int numSpecialEquivGroups(vector<string>& A) {
        int groupCount = 0;
        vector<bool> isGrouped(A.size(), false);
        for(int i = 0; i < (int)A.size(); i++) {
            if(isGrouped[i]) continue;
            groupCount++;
            for(int k = i + 1; k < (int)A.size(); k++) {
                if(isSpecialEquivalent(A[i], A[k])) {
                    isGrouped[k] = true;
                }
            }
        }
        return groupCount;
    }
};