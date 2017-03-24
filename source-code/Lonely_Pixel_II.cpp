class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int result = 0;
        int n = (int)picture.size();
        int m = (int)picture[0].size();
        vector<int> col(m, true);
        vector<int> mask(n, -1);
        for(int i = 0; i < n; i++) {
            int code = 0;
            int count = 0;
            for(int j = 0; j < m; j++) {
                if(picture[i][j] == 'B') {
                    code |= (1 << j);
                    count++;
                }
            }
            if(count == N) mask[i] = code;
        }
        for(int i = 0; i < n; i++) {
            if(mask[i] == -1) { continue; } // not candidate row
            for(int j = 0; j < m; j++) {
                if(!col[j]) { continue; } // not candidate col
                int count = 0;
                bool diff = false;
                int code = INT_MIN;
                for(int k = 0; k < n; k++) {
                    if(picture[k][j] == 'B') {
                        count++;
                        if(code == INT_MIN) {
                            code = mask[k];
                        }
                        if(code != mask[k]) {
                            diff = true;
                            // break;
                        }
                    }
                }
                if(!diff and count == N) {
                    result += N;
                }
                col[j] = false;
            }
        }
        return result;
    }
};