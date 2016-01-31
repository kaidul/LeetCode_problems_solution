class Solution {
public:
    bool isSG(string& num, int i, int j) {
        char ch[3] = {'1', '0', '8'};
        for(int k = 0; k < 3; ++k) {
            if(num[i] == ch[k] and num[j] == ch[k]) {
                return true;
            }    
        }
        if((num[i] == '6' and num[j] == '9') or (num[i] == '9' and num[j] == '6')) {
            return true;
        }
        return false;
    }
    bool isStrobogrammatic(string num) {
        int n = num.length();
        for(int i = 0, j = n - 1; i <= j; ++i, --j) {
            if(!isSG(num, i, j)) {
                return false;
            }
        }
        return true;
    }
};