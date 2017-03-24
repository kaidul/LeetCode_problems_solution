class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int result = 0;
        int n = (int)picture.size();
        int m = (int)picture[0].size();
        vector<bool> col(m, true);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(col[j]) {
                    if(picture[i][j] == 'B') {
                        int k = 0;
                        for(k = 0; k < n; k++) {
                            if(k != i and picture[k][j] != 'W') {
                                break;
                            }
                        }
                        if(k == n) {
                            k = 0;
                            for(k = j + 1; k < m; k++) {
                                if(picture[i][k] != 'W') {
                                    break;
                                }
                            }
                        }
                        if(k == m) {
                            result++;
                        }
                        col[j] = false;
                        break;
                    }
                }
            }
        }
        return result;
    }
};