class Solution {
    int countDigitOneRecur(int n, int Exp, unordered_map<int, int>& dp) {
        if(n <= 0) return 0;
        if(n <= 9) return 1;
        
        int result = 0;
        result += (n / Exp) * dp[Exp - 1];
        result += (n / Exp > 1) ? Exp : 0;
        result += (n / Exp == 1) ? n % Exp + 1 : 0;
        
        result += countDigitOneRecur(n % Exp, Exp / 10, dp);
        
        return result;
    }
public:
    int countDigitOne(int n) {
        if(n <= 0) return 0;
        int result = 0;
        unordered_map<int, int> dp;
        dp[9] = 1;
        for(int i = 9; i <= (INT_MAX - 9) / 10; i = i * 10 + 9) {
            dp[i * 10 + 9] = dp[i] * 10 + (i + 1);
        }
        int x = n;
        int Exp = 1;
        while(x / 10) {
            x /= 10;
            Exp *= 10;
        }
        result = countDigitOneRecur(n, Exp, dp);
        return result;
    }
};