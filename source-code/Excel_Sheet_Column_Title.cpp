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
class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";
        while(n) {
            if(n % 26 == 0) {
                ans = 'Z' + ans;
                n--;
            } else {
                ans = char('A' + (n % 26) - 1) + ans;
            }
            n /= 26;
        }
        return ans;
    }
};
