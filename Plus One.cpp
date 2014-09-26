class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int extra = 1, value;
        for(int i = digits.size() - 1; i >= 0; --i) {
            value = digits[i] + extra;
            extra = value / 10;
            digits[i] = (value % 10);
            if(extra <= 0) break;
        }
        if(extra) {
            digits.resize(digits.size() + 1);
            for(int i = digits.size() - 1; i >= 0; --i)
                digits[i + 1] = digits[i];
            digits[0] = extra;
        }
        return digits;
    }
};