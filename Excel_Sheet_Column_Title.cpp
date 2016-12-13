class Solution {
public:
    string convertToTitle(int n) {
        if(n < 27) {
            string result = "";
            result += 'A' + n - 1;
            return result;
        }
        if(n % 26 == 0) {
            return convertToTitle(n / 26 - 1) + 'Z';
        }
        return convertToTitle(n / 26) + convertToTitle(n % 26);
    }
};

// iterative
string convertToTitle(int n) {
    string ans;
    while (n-- != 0) {
        ans = char(int('A') + n % 26) + ans;
        n /= 26;
    }
    return ans;
}