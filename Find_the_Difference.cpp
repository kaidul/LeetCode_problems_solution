class Solution {
public:
    char findTheDifference(string s, string t) {
        // O(nlogn)
        /*
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for(int i = 0; i < (int)s.length(); ++i) {
            if(s[i] != t[i]) return t[i];
        }
        return t[t.length() - 1];
        */
        
        // O(n)
        const int MAX = 26;
        vector<int> freq(MAX, 0);
        for(int i = 0; i < t.length(); ++i) {
            freq[t[i] - 'a']++;
        }
        for(int i = 0; i < s.length(); ++i) {
            freq[s[i] - 'a']--;
        }
        for(int i = 0; i < MAX; ++i) {
            if(freq[i]) return (i + 'a');
        }
        return 0;
    }
};