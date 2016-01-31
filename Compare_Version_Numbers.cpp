class Solution {
public:
    int compareVersion(string version1, string version2) {
        size_t n1 = version1.length();
        size_t n2 = version2.length();
        char str1[n1], str2[n2];
        int val1, val2;
        char ch;
        for(int i = 0, j = 0, k; i < n1 or j < n2; ++i, ++j) {
            val1 = val2 = 0;
            
            if(i < n1) {
                ch = version1[i];
                k = 0;
                while(ch != '\0' and ch != '.') {
                    str1[k++] = ch;
                    ch = version1[++i];
                }
                str1[k] = '\0';
                val1 = atoi(str1);
            }

            if(j < n2) {
                ch = version2[j];
                k = 0;
                while(ch != '\0' and ch != '.') {
                    str2[k++] = ch;
                    ch = version2[++j];
                }
                str2[k] = '\0';
                val2 = atoi(str2);
            }

            if(val1 > val2) return 1;
            if(val1 < val2) return -1;
        }
        return 0;
    }
};