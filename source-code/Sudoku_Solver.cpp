class Solution {
    // believe me, I myself didn't like this function too.
    // but hashing pair as a key is more boring than this
    int getId(int x, int y) {
        int rx = x - (x % 3);
        int ry = y - (y % 3);
        if(rx == 0 and ry == 0) {
            return 1;
        } else if(rx == 0 and ry == 3) {
            return 2;
        } else if(rx == 0 and ry == 6) {
            return 3;
        } else if(rx == 3 and ry == 0) {
            return 4;
        } else if(rx == 3 and ry == 3) {
            return 5;
        } else if(rx == 3 and ry == 6) {
            return 6;
        } else if(rx == 6 and ry == 0) {
            return 7;
        } else if(rx == 6 and ry == 3) {
            return 8;
        } else if(rx == 6 and ry == 6) {
            return 9;
        }
    }
    
    bool solveSudokuRecur(int x, int y, vector<vector<bool>>& row, vector<vector<bool>>& col, vector<vector<bool>>& square, vector<vector<char>>& board) {
        if(x == board.size()) {
            return true;
        }
        int newY = y + 1;
        int newX = x + (newY / (int) board[0].size());
        newY = newY % (int) board[0].size();
        
        if(board[x][y] == '.') {
            int squareId = getId(x, y);
            for(char k = '1'; k <= '9'; ++k) {
                int val = (int)(k - '0'); 
                if(!row[x][val] and !col[y][val] and !square[squareId][val]) {
                    board[x][y] = k;
                    row[x][val] = col[y][val] = square[squareId][val] = true;
                    
                    if(solveSudokuRecur(newX, newY, row, col, square, board)) {
                        return true;
                    }
                    
                    board[x][y] = '.';
                    row[x][val] = col[y][val] = square[squareId][val] = false;
                }
            }
            return false;
        }
        
        return solveSudokuRecur(newX, newY, row, col, square, board);
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> row(m, vector<bool>(10, false));
        vector<vector<bool>> col(n, vector<bool>(10, false));
        vector<vector<bool>> square(10, vector<bool>(10, false));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] != '.')  {
                    int x = (int)(board[i][j] - '0');
                    row[i][x] = true;
                    col[j][x] = true;
                    square[getId(i, j)][x] = true;
                } 
            }
        }
        solveSudokuRecur(0, 0, row, col, square, board);
    }
};