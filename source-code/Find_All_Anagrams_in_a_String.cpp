class Solution {
    bool isAnagram(unordered_map<char, int>& count, unordered_map<char, int>& freq) {
        for(int i = 0; i <= 'z' - 'a'; ++i) {
            if(freq[i] != count[i]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.length();
        int m = s.length();
        vector<int> result;
        if(n > m) {
            return result;
        }
        unordered_map<char, int> freq;
        for(int i = 0; i < n; ++i) {
            freq[p[i] - 'a']++;    
        }
        unordered_map<char, int> count;
        for(int i = 0; i < n; ++i) {
            count[s[i] - 'a']++;
        }
        if(isAnagram(count, freq)) {
            result.push_back(0);
        }
        for(int left = 0, right = n; right < m; ++right) {
            count[s[left++] - 'a']--;
            count[s[right] - 'a']++;
            if(isAnagram(count, freq)) {
                result.push_back(left);
            }
        }
        return result;
    }
};