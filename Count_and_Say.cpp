class Solution {
public:
    string countAndSay(int n) {
        string result = "";
        if(n == 0) return result;
        result = "1";
        while(--n) {
            char prev = 'x';
            int count = 0;
            string tmp = "";
            for(int i = 0; i < result.length(); ++i) {
                if(prev != 'x' and prev != result[i]) {
                    tmp += (char)(count + '0');
                    tmp += prev;
                    prev = result[i];
                    count = 0;
                }
                if(prev == 'x') prev = result[i];
                count++;
            }
            tmp += (char)(count + '0');
            tmp += prev;
            result = tmp;
        }
        return result;
    }
};