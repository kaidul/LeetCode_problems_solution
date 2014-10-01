class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int n = strlen(s);
        if(n == 0) return 0;
        int len = 0, idx = n - 1;
        while(s[idx] == ' ') idx--;
        for(int i = idx; i >= 0 and s[i] != ' '; --i) ++len;
        return len;
    }
};