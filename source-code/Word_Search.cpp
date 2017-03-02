class Solution {
public:

    bool existUtils(vector<vector<char> > &board, string word, vector<vector<bool> > &visited, int x, int y, int indx) {
        if(indx == word.length() - 1) {
            return true;
        }
        if(y - 1 >= 0 and !visited[x][y - 1] and board[x][y - 1] == word[indx + 1]) {
            visited[x][y - 1] = true;
            if( existUtils(board, word, visited, x, y - 1, indx + 1) )
                return true;
            visited[x][y - 1] = false;
        }
        
        if(x - 1 >= 0 and !visited[x - 1][y] and board[x - 1][y] == word[indx + 1]) {
            visited[x - 1][y] = true;
            if( existUtils(board, word, visited, x - 1, y, indx + 1) )
                return true;
            visited[x - 1][y] = false;
        }
            
        
        if(y + 1 < board[0].size() and !visited[x][y + 1] and board[x][y + 1] == word[indx + 1]) {
            visited[x][y + 1] = true;
            if( existUtils(board, word, visited, x, y + 1, indx + 1) )
                return true;
            visited[x][y + 1] = false;
        }
            
        
        if(x + 1 < board.size() and !visited[x + 1][y] and board[x + 1][y] == word[indx + 1]) {
            visited[x + 1][y] = true;
            if( existUtils(board, word, visited, x + 1, y, indx + 1) )
                return true;
            visited[x + 1][y] = false;
        }
        
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                if(board[i][j] == word[0]) {
                    if(word.size() == 1) {
                        return true;    
                    } else {
                        vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));
                        visited[i][j] = true;
                        if(existUtils(board, word, visited, i, j, 0))
                            return true; 
                    }  
                }
            }
        }
        return false;
    }
};