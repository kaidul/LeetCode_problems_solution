class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length(), m = b.length();
        if(n == 0) return b;
        if(m == 0) return a;
        string result;
        int carry = 0, sum;
        int i = n - 1, j = m - 1;
        while(i >= 0 or j >= 0 or carry) {
            sum = carry + (i >= 0 ? (int)(a[i--] - '0') : 0) 
                + (j >= 0 ? (int)(b[j--] - '0') : 0);
            carry = sum / 2;
            sum %= 2;
            result += (char)(sum + '0');
        }
        reverse(result.begin(), result.end());
        return result;
    }
};