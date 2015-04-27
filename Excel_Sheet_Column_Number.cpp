class Solution {
public:
    int titleToNumber(string s) {
        int n = s.length();
        int result = 0;
        for(int k = 0, i = n - 1; i >= 0; k++, --i) {
            int factor = pow(26, i);
            result += (factor * (int(s[k] - 'A') + 1));
        }
        return result;
    }
};