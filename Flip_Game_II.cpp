class Solution {
    
    bool canWinRecur(string& s) {
    
        for(int i = 0; i < (int)s.length() - 1; ++i) {
    
            if(s[i] == '+' and s[i + 1] == '+') {
                s[i] = s[i + 1] = '-';
                bool success = !canWinRecur(s);
                s[i] = s[i + 1] = '+';
                
                if(success) {
                    return true;
                }
            }
    
        }
        return false;
    }
    
public:
    bool canWin(string s) {
        return canWinRecur(s);
    }
};