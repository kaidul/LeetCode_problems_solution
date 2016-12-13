class Solution {
public:
    string originalDigits(string s) {
        vector<int> digit(10, 0);
        vector<int> alpha(128, 0);
        for (char ch : s) {
            alpha[ch]++;
        }
        digit[0] = alpha['z'];
        digit[2] = alpha['w'];
        digit[4] = alpha['u'];
        digit[6] = alpha['x'];
        digit[8] = alpha['g'];
        digit[3] = alpha['h'] - digit[8];
        digit[5] = alpha['f'] - digit[4];
        digit[7] = alpha['v'] - digit[5];
        digit[1] = alpha['o'] - digit[0] - digit[2] - digit[4];
        digit[9] = alpha['i'] - digit[5] - digit[6] - digit[8];
        string result;
        for (int i = 0; i < 10; i++) {
            if (digit[i] > 0) {
                result += string(digit[i], '0' + i);
            }
        }
        return result;
    }
};