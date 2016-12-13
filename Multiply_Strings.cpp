class Solution {
public:
    string multiply(string num1, string num2) {
        string product = "";
        string result = "";
        string zeros = "";
        for(int i = num1.size() - 1; i >= 0; --i) {
            int digit1 = (int) (num1[i] - '0');
            int carry = 0;
            for(int j = num2.size() - 1; j >= 0; --j) {
                int digit2 = (int) (num2[j] - '0');
                int multply = digit1 * digit2;
                multply += carry;
                product += to_string(multply % 10);
                carry = multply / 10;
            }
            while(carry) {
                product += to_string(carry % 10);
                carry /= 10;
            }
            reverse(product.begin(), product.end());
            if(result.length() > 0) {
                string sum = "";
                for(int k = result.size() - 1, l = product.size() - 1; k >= 0 || l >= 0 || carry > 0; --k, --l) {
                    int d1 = k >= 0 ? (int) (result[k] - '0') : 0;
                    int d2 = l >= 0 ? (int) (product[l] - '0') : 0;
                    int total = d1 + d2 + carry;
                    sum += to_string(total % 10);
                    carry = total / 10;
                }
                reverse(sum.begin(), sum.end());
                result = sum;
            } else {
                result = product;
            }
            zeros += "0";
            product = zeros;
        }
        int indx = 0;
        while(indx < result.length() - 1 && result[indx] == '0') {
            indx++;
        }
        return result.substr(indx);
    }
};