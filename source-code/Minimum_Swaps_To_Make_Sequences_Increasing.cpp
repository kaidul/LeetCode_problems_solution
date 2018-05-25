class Solution {
    bool isSwappable(int indx, vector<int>& A, vector<int>& B) {
        return indx == 0 or (indx > 0 and A[indx] > B[indx - 1] and B[indx] > A[indx - 1]);
    }
    
    bool isOkay(int indx, vector<int>& A, vector<int>& B) {
        return indx == 0 or (indx > 0 and A[indx] > A[indx - 1] and B[indx] > B[indx - 1]);
    }
    
    int minSwap(int indx, bool swapped, vector<int>& A, vector<int>& B, vector<vector<int>>& dp) {
        if(indx == (int)A.size()) {
            return 0;
        }
        
        if(dp[indx][swapped] != -1) {
            return dp[indx][swapped];
        }
        
        int ret = INT_MAX;
        
        if(isOkay(indx, A, B)) {
            if(isSwappable(indx, A, B)) {
                swap(A[indx], B[indx]);
                ret = min(ret, 1 + minSwap(indx + 1, true, A, B, dp));
                swap(A[indx], B[indx]);
            }
            ret = min(ret, minSwap(indx + 1, false, A, B, dp));
        }
        
        if(isSwappable(indx, A, B)) {
            swap(A[indx], B[indx]);
            ret = min(ret, 1 + minSwap(indx + 1, true, A, B, dp));
            swap(A[indx], B[indx]);
        }
        
        return dp[indx][swapped] = ret;
    }
    
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = (int)A.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return minSwap(0, 0, A, B, dp);
    }
};
