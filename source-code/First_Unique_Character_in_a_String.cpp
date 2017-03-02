class Solution {
public:
    int firstUniqChar(string s) {
        if(s.empty()) return -1;
        int n = s.length();
        vector<int> freq(30, 0);
        for(int i = 0; i < n; ++i) {
            freq[s[i] - 'a']++;
        }
        for(int i = 0; i < n; ++i) {
            if(freq[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};