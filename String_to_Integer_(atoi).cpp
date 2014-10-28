class Solution {
public:
    int atoi(const char *str) {
        if (!str) return 0;
        int i = 0;
        bool pos = true;
        int res = 0;
        
        // removing trailing space
        while (str[i] == ' ') { 
            i++; 
        }
        
        // checking sign
        if (str[i] == '+') {
            pos = true; 
            i++;
        } else if (str[i] == '-') { 
            pos = false; 
            i++; 
        }
        
        if(!isdigit(str[i])) {
            return 0; 
        }
        
        while ( isdigit(str[i]) ) {
           if(pos and res > INT_MAX / 10) { 
               return INT_MAX;
           }
           if(pos and res == INT_MAX / 10 and int(str[i] - '0') >= 7) {
               return INT_MAX;
           }
           if (!pos and -res < INT_MIN / 10) {
               return INT_MIN;
           }
           if (!pos and -res == INT_MIN / 10 and int(str[i] - '0') >= 8) {
               return INT_MIN;
           }
           res = res * 10 + int(str[i++] - '0');
        }
        
             
        if(pos) { 
            return res;
        }
        return -res;
    }
};