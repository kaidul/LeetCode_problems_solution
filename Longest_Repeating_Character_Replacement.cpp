class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = (int)s.length();
        int result = 0;
        if(k == 0) {
            for(int i = 0; i < n; i++) {
                char ch = s[i];
                int len = 0; len++;
                while(i + 1 < n and s[i + 1] == ch) {
                    i++; len++;
                }
                result = max(result, len);
            }
            return result;
        }
        for(char ch = 'A'; ch <= 'Z'; ch++) {
            string tmp = s;
            int start = 0, end = 0;
            for(int i = 0, j = k; i < n and j > 0; i++, end++) {
                if(tmp[i] != ch) {
                    tmp[i] = ch;
                    j--;
                }
            }
            while(end < n and s[end] == ch) {
                end++;
            }
            result = max(result, end - start);
            int indx = start;
            while(end < n) {
                while(indx < end and s[indx] == ch) {
                    indx++;
                }
                if(indx < end) {
                    tmp[indx] = s[indx];
                    start = ++indx;
                }
                if(end < n) {
                    tmp[end] = ch;
                    end++;
                }
                while(end < n and s[end] == ch) {
                    end++;
                }
                result = max(result, end - start);
            }
        }
        return result;
    }
};