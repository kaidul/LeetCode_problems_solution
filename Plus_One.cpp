class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1, sum;
        for(int i = digits.size() - 1; i >= 0 and carry > 0; --i) {
            sum = digits[i] + carry;
            carry = sum / 10;
            digits[i] = (sum % 10);
        }
        if(carry) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};