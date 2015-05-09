class Solution {
public:
    // naive O(m *  (n - m  + 1))
    int strStr(char *haystack, char *needle) {
        int n = strlen(haystack); //1
        int m = strlen(needle); //1
        // if(m == 0) return 0;
        for(int i = 0, j; i <= n - m; ++i) { 
            bool flag = true;
            for(j = 0; j < m; ++j) {
                if(haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) return i;
        }
        return -1;
    }

    // KMP O(m)
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        if(m > n) return -1;
        if(m == 0 and n == 0) return 0;
        int LPS[m + 1];
        
        int len = 0;
        LPS[0] = 0;
        for(int i = 1; i < m; ) {
            if(needle[i] == needle[len]) {
                LPS[i++] = ++len;
            } else {
                if(len == 0) {
                    LPS[i++] = 0;
                } else {
                    len = LPS[len - 1];
                }
            }
        }
        
        for(int i = 0, j = 0; i < n; ) {
            if(needle[j] == haystack[i]) {
                j++, i++;
            }
            
            if(j == m) {
                // found first occurance
                return i - j;
            } else if(needle[j] != haystack[i]) {
                if(j == 0) {
                    i++;
                } else {
                    j = LPS[j - 1];
                }
            }
        }
        return -1;
    }
};