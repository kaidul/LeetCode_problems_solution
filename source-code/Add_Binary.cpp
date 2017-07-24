class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length(), m = b.length();
        if(n == 0) return b;
        if(m == 0) return a;
        string result;
        int carry = 0, sum;
        int i = n - 1, j = m - 1;
        while(i >= 0 and j >= 0) {
            sum = carry + (int)(a[i--] - '0') + (int)(b[j--] - '0');
            if(sum == 2) sum = 10;
            else if(sum == 3) sum = 11;
            carry = sum / 10;
            sum %= 10;
            result += (char)(sum + '0');
        }
        while(j >= 0) {
            sum = (int)(b[j--] - '0') + carry;
            if(sum == 2) sum = 10;
            else if(sum == 3) sum = 11;
            carry = sum / 10;
            sum %= 10;
            result += (char)(sum + '0');
        }
        while(i >= 0) {
            sum = (int)(a[i--] - '0') + carry;
            if(sum == 2) sum = 10;
            else if(sum == 3) sum = 11;
            carry = sum / 10;
            sum %= 10;
            result += (char)(sum + '0');
        }
        if(carry) result += (char)(carry + '0');
        reverse(result.begin(), result.end());
        return result;
    }
};