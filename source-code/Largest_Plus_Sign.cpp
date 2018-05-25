class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> left(N, vector<int>(N, 1));
        vector<vector<int>> right(left), up(left), down(left);
        
        for(int i = 0; i < mines.size(); i++) {
            int x = mines[i][0], y = mines[i][1];
            left[x][y] = right[x][y] = up[x][y] = down[x][y] = 0;
        }
        
        for(int i = 0; i < N; i++) {
            for(int j = 0, k = N - 1; j < N; j++, k--) {
                if(left[i][j] and j > 0) {
                    left[i][j] += left[i][j - 1];   
                }
                if(right[i][k] and k + 1 < N) {
                    right[i][k] += right[i][k + 1];
                }
                if(up[j][i] and j > 0) {
                    up[j][i] += up[j - 1][i]; 
                }
                if(down[k][i] and k + 1 < N) {
                    down[k][i] += down[k + 1][i];
                }
            }
        }
        
        int result = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0, l = N - 1; j < N; j++, l--) {
                if(left[i][j]) {
                    int k = left[i][j] / 2;
                    
                    int centerX = i, centerY = j - k;
                    if(centerX - k >= 0 and centerX + k < N and centerY - k >= 0) {
                        bool plus = min(min(right[centerX][centerY - k], up[centerX + k][centerY]), down[centerX - k][centerY]) >= left[i][j];
                        if(plus) {
                            int order = k + 1;
                            result = max(result, order);
                        }
                    }
                }
                
                if(right[i][l]) {
                    int k = right[i][l] / 2;
                    
                    int centerX = i, centerY = l + k;
                    if(centerX - k >= 0 and centerX + k < N and centerY + k < N) {
                        bool plus = min(min(left[centerX][centerY + k], up[centerX + k][centerY]), down[centerX - k][centerY]) >= right[i][l];
                        if(plus) {
                            int order = k + 1;
                            result = max(result, order);
                        }
                    }
                }
                
                if(up[j][i]) {
                    int k = up[j][i] / 2;
                    
                    int centerX = j - k, centerY = i;
                    if(centerX - k >= 0 and centerY + k < N and centerY - k >= 0) {
                        bool plus = min(min(right[centerX][centerY - k], left[centerX][centerY + k]), down[centerX - k][centerY]) >= up[j][i];
                        if(plus) {
                            int order = k + 1;
                            result = max(result, order);
                        }
                    }
                }
                
                if(down[l][i]) {
                    int k = down[l][i] / 2;
                    
                    int centerX = l + k, centerY = i;
                    if(centerX + k < N and centerX + k < N and centerY - k >= 0) {
                        bool plus = min(min(right[centerX][centerY - k], left[centerX][centerY + k]), up[centerX + k][centerY]) >= down[l][i];
                        if(plus) {
                            int order = k + 1;
                            result = max(result, order);
                        }
                    }
                }
            }
        }
        return result;
    }
};
