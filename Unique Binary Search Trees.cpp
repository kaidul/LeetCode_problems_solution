class Solution {
public:
    /**
    trees[n] is the number of trees with exactly n nodes. 
    There is 1 trees with 0 nodes, hence trees[0] == 1. 
    For a given n > 0 there is a root node and two children trees whose total size is: n-1

    trees[n-1] possible trees on the left and trees[0] on the right
    trees[n-2] possible trees on the left and trees[1] on the right
    ...
    trees[1] possible trees on the left and trees[n-1-1] on the right
    trees[0] possible trees on the left and trees[n-1] on the right
    When you have trees[k] possible trees on the left, and trees[l] on the right, 
    it makes trees[k]*trees[l] possible combinations. 
    This means:

    trees[n] = trees[n-1]*trees[0]
             + trees[n-2]*trees[1]
             + ...
             + trees[1]*trees[n-2]
             + trees[0]*trees[n-1]
    The outer loop compute all trees[n]. 
    The inner loop compute each of these using the decomposition shown above (and the computations of all the values before n).
    **/
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            int sum = 0;
            for (int j = 0; j < i; j++) {
                sum += dp[j] * dp[i - 1 - j];
            }
            dp[i] = sum;
        }
        return dp[n];   
    }
    // Exhaustive Search - TLE
    /*
    int numTrees(int n) {
        if (n==0){return 1;}
        if (n==1){return 1;}
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += numTrees(i - 1) * numTrees(n - i);
        }
        return sum;
    }
    */
};