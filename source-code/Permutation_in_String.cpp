class Solution {
    const static int MAX = 26;
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(MAX, 0);
        int n = (int)s1.length();
        for(int i = 0; i < n; i++) {
            freq[s1[i] - 'a']++;
        }
        int i = 0, k = 0;
        int m = (int)s2.length();
        while(k < m) {
            freq[s2[k] - 'a']--;
            if(freq[s2[k] - 'a'] < 0) {
                while(i <= k and freq[s2[k] - 'a'] < 0) {
                    freq[s2[i] - 'a']++;
                    i++;
                }
            }
            if(k - i + 1 == n) {
                return true;
            }
            k++;
        }
        return false;
    }
};