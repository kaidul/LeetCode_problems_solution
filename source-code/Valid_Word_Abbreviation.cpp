class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        if(word.empty()) return true;
        int n = (int)word.length();
        int m = (int)abbr.length();
        int i = 0, k = 0;
        while(i < m and k < n) {
            if(isalpha(abbr[i])) {
                if(abbr[i] != word[k])
                    return false;
                ++i, ++k;
            } else {
                if(abbr[i] == '0') return false;
                int length = 0;
                while(isdigit(abbr[i])) {
                    length = length * 10 + (int)(abbr[i] - '0');
                    ++i;
                }
                k += length;
            }
        }
        return k == n and i == m;
    }
};