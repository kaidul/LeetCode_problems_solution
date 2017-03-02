class Solution {
    int toInt(string s) {
        int n = 0;
        istringstream sin(s);
        sin >> n;
        return n;
    }
public:
    int calculate(string s) {
        if(s.empty()) return 0;
        stack<int> stk;
        int i = 0;
        int n = (int)s.length();
        while(i < n) {
            while(i < n and s[i] == ' ') {
                i++;
            }
            if(s[i] == ')') {
                int sum = 0;
                while(!stk.empty()) {
                    int top = stk.top();
                    stk.pop();
                    if(top == numeric_limits<int>::max()) {
                        stk.push(sum);
                        break;
                    }
                    if(top == numeric_limits<int>::min()) {
                        sum *= -1;
                        stk.push(sum);
                        break;
                    }
                    sum += top;
                }
                ++i;
            } 
            else {
                int sign = 1;
                if(s[i] == '-') {
                    sign = -1;
                    ++i;
                } else if(s[i] == '+') {
                    sign = 1;
                    ++i;
                }
                while(i < n and s[i] == ' ') {
                    i++;
                }
                if(s[i] == '(') {
                    if(sign == 1) {
                        stk.push(numeric_limits<int>::max());
                    } else {
                        stk.push(numeric_limits<int>::min());
                    }
                    ++i;
                } 
                else {
                    int start = i;
                    while(i < n and s[i] >= '0' and s[i] <= '9') {
                        ++i;
                    }
                    int num = toInt(s.substr(start, i - start));
                    num *= sign;
                    stk.push(num);    
                }
            }
        }
        int result = 0;
        while(!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        
        return result;
    }
};