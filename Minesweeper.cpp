class Solution {
    const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
    bool valid(int x, int y, vector<vector<char>>& board) {
        int n = (int)board.size();
        int m = (int)board[0].size();
        return x >= 0 and y >= 0 and x < n and y < m;
    }
    
    int countMine(int x, int y, vector<vector<char>>& board) {
        int cnt = 0;
        for(int i = 0; i < 8; i++) {
            int X = x + dx[i];
            int Y = y + dy[i];
            cnt += (valid(X, Y, board) and board[X][Y] == 'M');
        }
        return cnt;
    }
    
    void reveal(int x, int y, vector<vector<char>>& board) {
        int mine = countMine(x, y, board);
        if(mine > 0) {
            board[x][y] = mine + '0';
            return;
        }
        board[x][y] = 'B';
        for(int i = 0; i < 8; i++) {
            int X = x + dx[i];
            int Y = y + dy[i];
            if(valid(X, Y, board) and board[X][Y] == 'E') {
                reveal(X, Y, board);
            }
        }
    }
    
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y = click[1];
        switch(board[x][y]) {
            case 'M':
                board[x][y] = 'X';
                break;
            case 'E':
                reveal(x, y, board);
                break;
            default:
                break;
        }
        return board;
    }
};