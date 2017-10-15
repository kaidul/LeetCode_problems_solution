class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int i = 0;
        vector<int> consecutiveCnt;
        while(i < n) {
            int k = 1;
            i++;
            while(i < n and s[i] == s[i - 1]) {
                ++k; i++;
            }
            consecutiveCnt.push_back(k);
        }
        int result = 0;
        for(int i = 0; i < consecutiveCnt.size() - 1; i++) {
            result += min(consecutiveCnt[i], consecutiveCnt[i + 1]);
        }
        return result;
    }
};