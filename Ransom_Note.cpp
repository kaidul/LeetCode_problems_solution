class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(30, 0);
        for(int i = 0; i < magazine.length(); ++i) {
            freq[magazine[i] - 'a']++;
        }
        for(int i = 0; i < ransomNote.length(); ++i) {
            if(!freq[ransomNote[i] - 'a']) {
                return false;
            }
            freq[ransomNote[i] - 'a']--;
        }
        return true;
    }
};