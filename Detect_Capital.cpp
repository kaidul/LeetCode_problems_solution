class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = (int)word.length();
        if(n <= 1) return true;
        bool firstUpper = false;
        if(isupper(word[0])) {
            firstUpper = true;
        }
        bool allUpper = true, allLower = true;
        for(int i = 1; i < n; i++) {
            if(isupper(word[i])) {
                allLower = false;
            } else {
                allUpper = false;
            }
        }
        if(!allUpper and !allLower) {
            return false;
        }
        if(firstUpper) {
            return true;
        }
        return allLower;
    }
};