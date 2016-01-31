class Solution {
public:
    void findStrobogrammaticRecur(int left, int right, string& str, vector<string>& result) {
        if(left > right) {
            result.push_back(str);
            return;
        }
        if((left == 0 and left == right) or left > 0) {
            str[left] = str[right] = '0';
            findStrobogrammaticRecur(left + 1, right - 1, str, result);
        }
        str[left] = str[right] = '1';
        findStrobogrammaticRecur(left + 1, right - 1, str, result);
        str[left] = str[right] = '8';
        findStrobogrammaticRecur(left + 1, right - 1, str, result);
        if(left < right) {
            str[left] = '6'; str[right] = '9';
            findStrobogrammaticRecur(left + 1, right - 1, str, result);
            swap(str[left], str[right]);
            findStrobogrammaticRecur(left + 1, right - 1, str, result);    
        }
    }
    vector<string> findStrobogrammatic(int n) {
        vector<string> result;
        string str;
        str.resize(n);
        findStrobogrammaticRecur(0, n - 1, str, result);
        return result;
    }
};