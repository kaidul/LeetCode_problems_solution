class Solution {
public:
    // TLE
    void canJumpUtils(int indx, int A[], int n, bool &result) {
        if(result) return;
        if(indx > n - 1) {
            result = true;
            return;
        }
        if(A[indx] == 0) return;
        for(int i = A[indx]; i > 0; --i) {
            canJumpUtils(indx + i, A, n, result);
        }
        
    }
    
    // TLE (O(n^2) DP)
    int canJumpDp(int indx, int A[], int n, vector<int> &dp) {
        if(indx > n - 1) {
            return 1;
        }
        if(A[indx] == 0) return 0;
        if(dp[indx] != -1) return dp[indx];
        for(int i = A[indx]; i > 0; --i) {
            dp[indx] = canJumpDp(indx + i, A, n, dp);
            if(dp[indx] == 1) break;
        }
        return dp[indx];
    }
    
    bool canJump(int A[], int n) {
        // if(n == 0) return true;
        
        // Complete Search - TLE
        // bool result = false;
        // canJumpUtils(0, A, n, result);
        // return result;
        
        // dp - TLE
        //vector<int> dp(n + 1, -1);
        //return canJumpDp(0, A, n, dp);

        if (n==0) {return false;}
        if (n==1) {return true;}
         
        int m = 0;
        for (int i = 0; i < n; i++) {
            if(i <= m) {
                m = max(m, A[i] + i);
                if (m >= n - 1) { return true; }
            } else {
                break;
            }
        }
        return false;
    }
};