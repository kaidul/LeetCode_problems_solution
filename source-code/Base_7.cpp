class Solution {
public:
    string convertToBase7(int num) {
        int sign = (num >= 0) ? 1 : -1;
        num = abs(num);
        string result;
        while(num > 0) {
            result += to_string(num % 7);
            num /= 7;
        }
        reverse(result.begin(), result.end());
        if(sign < 0) {
            result = "-" + result;
        }
        if(result.empty()) {
            result = "0";
        }
        return result;
    }
};