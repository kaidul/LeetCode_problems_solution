class Solution {
public:
    string addStrings(string num1, string num2) {
        string result = "";
        int carry = 0, sum = 0;
        int m = (int)num1.length(), n = (int)num2.length();
        int i = m - 1, j = n - 1;
        while(i >= 0 or j >= 0 or carry) {
            int digit1 = (i >= 0 ? num1[i] - '0' : 0);
            int digit2 = (j >= 0 ? num2[j] - '0' : 0);
            sum = digit1 + digit2 + carry;
            result += to_string(sum % 10);
            carry = sum / 10;
            --i, --j;
        }
        reverse(result.begin(), result.end());
        
        return result;
    }
};