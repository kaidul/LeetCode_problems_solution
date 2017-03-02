class Solution {
public:
    int compare(string const& lhs, string const& rhs) {
        int n1 = lhs.length();
        int n2 = rhs.length();
        int i = 0, j = 0;
        while(i < n1 and lhs[i] == '0') {
            ++i;
        }
        while(j < n1 and rhs[j] == '0') {
            ++j;
        }
        if(n1 - i != n2 - j) {
            return (n1 - i > n2 - j) ? 1 : -1;
        }
        for(; i < n1 and j < n2; ++i, ++j) {
            if(lhs[i] != rhs[j]) {
                return (lhs[i] > rhs[j]) ? 1 : -1;
            }
        }
        return 0;
    }
    int compareVersion(string version1, string version2) {
        size_t n1 = version1.length();
        size_t n2 = version2.length();
        char str1[n1], str2[n2];
        char ch;
        for(int i = 0, j = 0, k; i < n1 or j < n2; ++i, ++j) {
            
            if(i < n1) {
                ch = version1[i];
                k = 0;
                while(ch != '\0' and ch != '.') {
                    str1[k++] = ch;
                    ch = version1[++i];
                }
                str1[k] = '\0';
            } else {
                str1[0] = '\0';
            }
            
            if(j < n2) {
                ch = version2[j];
                k = 0;
                while(ch != '\0' and ch != '.') {
                    str2[k++] = ch;
                    ch = version2[++j];
                }
                str2[k] = '\0';
            } else {
                str2[0] = '\0';
            }
            
            int ret = compare(str1, str2);
            if(ret != 0) {
                return ret;
            }
            
        }
        return 0;
    }
};