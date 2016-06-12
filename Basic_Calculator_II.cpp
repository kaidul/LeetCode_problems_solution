class Solution {
    int toInt(string s) {
        int n = 0;
        istringstream sin(s);
        sin >> n;
        return n;
    }
    
    string toString(int n) {
        ostringstream oss;
        oss << n;
        oss.flush();
        return oss.str();
    } 
    
public:
    int calculate(string s) {
        if(s.empty()) return 0;
        
        for(int i = 0; i < (int)s.length(); ) {
            if(s[i] == '*' or s[i] == '/') {
                
                int left = i - 1;
                while(left >= 0  and s[left] == ' ') {
                    left--;
                }
                int end = left + 1;
                while(left >= 0 and s[left] >= '0' and s[left] <= '9') {
                    left--;
                }
                int start = left + 1;
                int sign;
                while(left >= 0 and s[left] == ' ') {
                    left--;
                }
                sign = (left >= 0 and s[left] == '-') ? -1 : 1;
                if(left < 0) left = 0;
                int a = toInt(s.substr(start, end - start));
                a *= sign;
                
                int right = i + 1;
                while(right < (int)s.length() and s[right] == ' ') {
                    right++;
                }
                sign = (s[right] == '-') ? -1 : 1;
                if(s[right] == '+' or s[right] == '-') right++;
                while(right < (int)s.length() and s[right] == ' ') {
                    right++;
                }
                start = right;
                while(right < (int)s.length() and s[right] >= '0' and s[right] <= '9') {
                    right++;
                }
                int b = toInt(s.substr(start, right - start));
                b *= sign;
                
                int product;
                if(s[i] == '*') {
                    product = a * b;
                } else {
                    product = a / b;
                }
                
                string prefix = s.substr(0, left);
                string middle = toString(product);
                if(middle[0] != '-') middle = '+' + middle;
                s = prefix + middle + s.substr(right);
                i = (int) prefix.length() + (int)middle.length();
            } else {
                ++i;
            }
        }
        int result = 0;
        int i = 0;
        while(i < (int)s.length()) {
            while(i < (int)s.length() and s[i] == ' ') {
                ++i;
            }
            int sign = 1;
            if(s[i] == '+') {
                sign = 1;
                i++;
            } else if(s[i] == '-') {
                sign = -1;
                ++i;
            }
            int start = i;
            while(i < (int)s.length() and s[i] >= '0' and s[i] <= '9') {
                i++;
            }
            int a = toInt(s.substr(start, i - start));
            a *= sign;
            
            result += a;
        }
        return result;
    }
};