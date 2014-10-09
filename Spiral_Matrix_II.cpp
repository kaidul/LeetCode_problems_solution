class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > result(n, vector<int>(n));
        if(n == 0) return result;
        int len = (n & 1) ? (n + 1) / 2 : n / 2;
        int cnt = 0;
        for(int i = 0; i < len; ++i) {
            
            for(int j = i; j < n - i; ++j)
                result[i][j] = ++cnt;
            
            for(int j = i + 1; j < n - i; ++j)
                result[j][n - 1 - i] = ++cnt;
            
            for(int j = n - 1 - i - 1; j >= i; --j)
                result[n - 1 - i][j] = ++cnt;
            
            for(int j = n - 1 - i - 1; j > i; --j)
                result[j][i] = ++cnt;
        }
        return result;
    }
};