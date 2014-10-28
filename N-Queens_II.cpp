class Solution {
public:

    bool isPlace(int queen, int row, int *arr) {
        for(int prev = 1; prev < queen; ++prev) {
            if ( arr[prev] == row or abs(arr[prev] - row) == abs(prev - queen) ) 
                return false;
        }
        return true;
    }

    int nQueen(int queen, int &count, int n, int *arr) {
        for(int row = 1; row <= n; ++row) {
            if(isPlace(queen, row, arr)) {
                arr[queen] = row; // arr[i] = j means there is a queen in jth row and ith column
                if(queen == n) ++count;
                else nQueen(queen + 1, count, n, arr);
            }
        }
    }

    int totalNQueens(int n) {
        int arr[n + 1];
        int count = 0;
        nQueen(1, count, n, arr);
        return count;
    }
};