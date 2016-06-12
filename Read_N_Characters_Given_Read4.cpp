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
        int cnt = 0;
        char* buf4 = new char[4];
        while(cnt < n) {
            int len = read4(buf4);
            for(int i = 0; i < min(len, n - cnt); ++i) {
                buf[cnt + i] = buf4[i];
            }
            cnt += min(len, n - cnt);
            if(len < 4) {
                break;
            }
        }
        return cnt;
    }
};