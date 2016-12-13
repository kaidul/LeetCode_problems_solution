class Solution {
public:

    bool isPlace(int queen, int row, vector<int>& arr) {
        for(int prev = 1; prev < queen; ++prev) {
            if ( arr[prev] == row or abs(arr[prev] - row) == abs(prev - queen) ) 
                return false;
        }
        return true;
    }

    int nQueen(int queen, int n, vector<int>& arr) {
        if(queen > n) {
            return 1;
        }
        int ret = 0;
        for(int row = 1; row <= n; ++row) {
            if(isPlace(queen, row, arr)) {
                arr[queen] = row; // arr[i] = j means there is a queen in jth row and ith column
                ret += nQueen(queen + 1, n, arr);
            }
        }
        return ret;
    }

    int totalNQueens(int n) {
        vector<int>arr(n + 1);
        return nQueen(1, n, arr);
    }
};