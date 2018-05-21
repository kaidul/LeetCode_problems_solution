class Solution {
public:
    string countAndSay(int n) {
        string result = "";
        if(n == 0) return result;
        result = "1";
        while(--n) {
            string tmp = "";
            for(int i = 0; i < result.length(); i++) {
                int count = 1;
                char digit = result[i];
                while(i + 1 < result.length() and result[i] == result[i + 1]) {
                    i++;
                    count++;
                }
                tmp += char(count + '0');
                tmp += digit;
            }
            result = tmp;
        }
        return result;
    }
};