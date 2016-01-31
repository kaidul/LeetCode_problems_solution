class Solution {
public:

    bool isPlace(int queen, int col, int *arr) {
        for(int prev = 1; prev < queen; ++prev) {
            if(arr[prev] == col or abs(arr[prev] - col) == abs(prev - queen))
                return false;
        }
        return true;
    }

    void solveNQueensUtils(int queen, vector<vector<string> > &result, vector<string> &solution, string Row, int n, int *arr) {
        for(int col = 1; col <= n; ++col) {
            if(isPlace(queen, col, arr)) {
                arr[queen] = col; // queen <=> row
                Row[col - 1] = 'Q';
                solution.push_back(Row);
                Row[col - 1] = '.';

                if(queen == n) result.push_back(solution);
                else solveNQueensUtils(queen + 1, result, solution, Row, n, arr);

                solution.pop_back();
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        vector <vector <string> > result;
        vector <string> solution;
        int arr[n + 1];
        string Row;
        for(int k = 0; k < n; ++k) Row += '.';
        solveNQueensUtils(1, result, solution, Row, n, arr);
        return result;
    }
};