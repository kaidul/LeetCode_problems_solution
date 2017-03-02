class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = (int)board.size();
        if(n == 0) return;
        int m = (int)board[0].size();
        if(m == 0) return;
        int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
        int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int liveNeighs = 0;
                for(int k = 0; k < sizeof(dx) / sizeof(dx[0]); ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    liveNeighs += (x >= 0 and y >= 0 and x < n and y < m and (board[x][y] & 1));
                }
                if(board[i][j] & 1) {
                    if(liveNeighs == 2 or liveNeighs == 3) {
                        board[i][j] |= 3;
                    }
                } else {
                    if(liveNeighs == 3) {
                        board[i][j] |= 2;
                    }
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};