class Solution {
    string toBinary(int n) {
        string binary;
        while(n) {
            binary += to_string(n % 2);
            n /= 2;
        }
        reverse(binary.begin(), binary.end());
        return binary;
    }
    
    int findIntegers(int indx, int prevDigit, bool smaller, string const& binary, vector<vector<vector<int>>>& dp) {
        if(indx == (int)binary.length()) {
            return 1;
        }
        if(dp[indx][prevDigit][smaller] != -1) {
            return dp[indx][prevDigit][smaller];
        }
        int ret = 0;
        int limit = smaller ? 1 : binary[indx] - '0';
        for(int d = 0; d <= limit; d++) {
            if(d and prevDigit) { continue; }
            ret += findIntegers(indx + 1, d, smaller or d < limit, binary, dp);
        }
            
        return dp[indx][prevDigit][smaller] = ret;
    }
public:
    int findIntegers(int num) {
        string binary = toBinary(num);
        vector<vector<vector<int>>> dp(32, vector<vector<int>>(2, vector<int>(2, -1)));
        int result = 0;
        int digit = binary[0] - '0';
        for(int d = 0; d <= digit; d++) {
            result += findIntegers(1, d, d < digit, binary, dp);    
        }
        return result;
    }
};