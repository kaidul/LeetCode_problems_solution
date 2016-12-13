class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0) return 0;
        int m = board[0].size();
        if(m == 0) return 0;
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(board[i][j] == 'X' and
                   (i == 0 or board[i - 1][j] != 'X') and 
                   (j == 0 or board[i][j - 1] != 'X') ) {
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};