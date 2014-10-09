class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        unordered_map <char, bool> row;
        unordered_map <char, bool> col;
        unordered_map <char, bool> grid;
        
        for(int i = 0; i < 9; ++i) {
            row.clear();
            col.clear();
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] != '.') {
                    if(row[ board[i][j] ]) {
                        return false;
                    } else {
                        row[ board[i][j] ] = true; 
                    }   
                }
                
                if(board[j][i] != '.') {
                    if( col[ board[j][i] ]) {
                        return false;
                    } else {
                        col[ board[j][i] ] = true; 
                    }
                }
            }
        }
            
        for(int i = 0; i < 9; i += 3) {
            for(int j = 0; j < 9; j += 3) {
                grid.clear();
                for(int k = i; k < i + 3; k++) {
                    for(int l = j; l < j + 3; l++) {
                        if(board[k][l] != '.') {
                            if(grid[ board[k][l] ]) {
                                return false;
                            } else {
                                grid[ board[k][l] ] = true;
                            }   
                        }
                    }
                }
            }
        }
        return true;
    }
};