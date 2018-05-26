// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int idx = 0;
        char* buf4 = new char[4];
        while(idx < n) {
            int len = read4(buf4);
            for(int i = 0, m = min(len, n - idx); i < m; ++i) {
                buf[idx++] = buf4[i];
            }
            if(len < 4) {
                break;
            }
        }
        return idx;
    }
};
