class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int row = matrix.size();
        if(row == 0) return 0;
        int col = matrix[0].size();
        vector<vector<int> > dp(row, vector<int>(col));
        
        for(int i = 0; i < row; ++i) {
            int k = 0;
            for(int j = 0; j < col; ++j) {
                dp[i][j] = matrix[i][j] == '1' ? k = k + 1 : k = 0;
            }
        }
        
        int item, Max = 0;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(dp[i][j]) {
                    item = dp[i][j];
                    Max = max(Max, item);
                    for(int k = i + 1, l = 2; k < row; k++, l++) {
                        if(dp[k][j]) {
                            if(dp[k][j] < item)
                                item = dp[k][j];
                            Max = max(Max, item * l);
                        } else {
                            break;
                        }
                    }
                }
            }
        }        
        return Max;
    }
};