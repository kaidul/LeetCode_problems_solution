class Solution {
public:
    int myAtoi(string str) {
        if(str.empty()) return 0;
        int i = 0;
        bool positive = true;
        int result = 0;
        
        // removing white space
        while(str[i] == ' ') {
            i++;
        }

        // checking sign
        if(str[i] == '-') {
            positive = false;
            i++;
        } else if(str[i] == '+') {
            positive = true;
            i++;
        }
        
        if(!isdigit(str[i])) {
            return 0;
        }
        
        while(isdigit(str[i])) {
            if(positive && result > INT_MAX / 10) {
                return INT_MAX;
            }
            
            if(positive && result == INT_MAX / 10 && int(str[i] - '0') >= 7) {
                return INT_MAX;
            }
            
            if(!positive && -result < INT_MIN / 10) {
                return INT_MIN;
            }
            
            if(!positive && -result == INT_MIN / 10 && int(str[i] - '0') >= 8) {
                return INT_MIN;
            }
            
            result = result * 10 + int(str[i++] - '0');
        }
        if(!positive) result = -result;
        return result;
    }
};