class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int row = board.size();
        if (row == 0)return;
        int col = board[0].size();

        vector<vector<bool> > visited(row, vector<bool>(col, false));
        queue<pair<int, int> > q;

        for(int i = 0; i < col; i++) {
            if (board[0][i] == 'O') {
                q.push(make_pair(0, i));
                visited[0][i] = true;
            }
        }

        for(int i = 1; i < row - 1; i++) {
            if(board[i][0] == 'O') {
                q.push(make_pair(i, 0));
                visited[i][0] = true;
            }
        }

        for(int i = 0; i < col; i++) {
            if(board[row - 1][i] == 'O') {
                q.push(make_pair(row - 1, i));
                visited[row - 1][i] = true;
            }
        }

        for(int i = 1; i < row - 1; i++) {
            if (board[i][col - 1] == 'O') {
                q.push(make_pair(i, col - 1));
                visited[i][col - 1] = true;
            }
        }

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if(i - 1 > 0 and board[i - 1][j] == 'O' and !visited[i - 1][j]) {
                visited[i - 1][j] = true;
                q.push(make_pair(i - 1, j));
            }
            if(i + 1 < row - 1 and board[i + 1][j] == 'O' and !visited[i + 1][j]) {
                visited[i + 1][j] = true;
                q.push(make_pair(i + 1, j));
            }
            if(j - 1 > 0 and board[i][j - 1] == 'O' and !visited[i][j - 1]) {
                visited[i][j - 1] = true;
                q.push(make_pair(i,j - 1));
            }
            if(j + 1 < col - 1 and board[i][j + 1] =='O' and !visited[i][j + 1]) {
                visited[i][j + 1] = true;
                q.push(make_pair(i,j + 1));
            }
        }

        for(int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O' and !visited[i][j]) {
                    board[i][j]= 'X';
                }
            }
        }
    }
};