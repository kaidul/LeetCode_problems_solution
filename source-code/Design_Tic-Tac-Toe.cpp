class TicTacToe {
    vector<vector<int>> board;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        if(n == 0) return;
        board.resize(n, vector<int>(n, 0));
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        // --row, --col;
        board[row][col] = player;
        int n = (int)board.size();
        
        bool isRow = true;
        bool isCol = true;
        bool isDiag1 = true;
        bool isDiag2 = true;
        for(int i = 0, j = n - 1; i < n; ++i, --j) {
            isRow = isRow and (board[row][i] == player);
            isCol = isCol and (board[i][col] == player);
            isDiag1 = isDiag1 and (board[i][i] == player);
            isDiag2 = isDiag2 and (board[i][j] == player);
        }
        
        if(isRow or isCol or isDiag1 or isDiag2) {
            return player;
        }
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */