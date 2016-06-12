// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    queue <char> Q;
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int cnt = 0;
        char* buf4 = new char[4];
        while(true) {
            int len = read4(buf4);
            for(int i = 0; i < len; ++i) {
                Q.push(buf4[i]);
            }
            len = min(n - cnt, (int) Q.size());
            for(int i = 0; i < len; ++i) {
                buf[cnt++] = Q.front();
                Q.pop();
            }
            if(len == 0) {
                break;
            }
        }
        return cnt;
    }
};