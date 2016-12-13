class Solution {
    bool canIWin(int maxChoosableInteger, int desiredTotal, int mask, vector<bool>& visited, vector<bool>& dp) {
        if(desiredTotal <= 0) {
            return false;
        }
        if(visited[mask]) {
            return dp[mask];
        }
        bool canWin = false;
        for(int i = 1; i <= maxChoosableInteger; i++) {
            if(!(mask & (1 << i))) {
                canWin |= !canIWin(maxChoosableInteger, desiredTotal - i, mask | (1 << i), visited, dp);
                if(canWin) {
                    break;
                }
            }
        }
        visited[mask] = true;
        return dp[mask] = canWin;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger >= desiredTotal) {
            return true;
        }
        int totalPossible = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
        if(totalPossible < desiredTotal) {
            return false;
        }
        int mask = 0;
        const int maxMask = 1 << (maxChoosableInteger + 1);
        vector<bool> dp(maxMask, false);
        vector<bool> visited(maxMask, false);
        return canIWin(maxChoosableInteger, desiredTotal, mask, visited, dp);
    }
};