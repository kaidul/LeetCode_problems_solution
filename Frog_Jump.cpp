class Solution {
    bool canCross(int indx, int unit, vector<int>& stones, unordered_map<int, int>& stoneMap, vector<vector<bool>>& visited, vector<vector<bool>>& dp) {
        if(indx == stones.size() - 1) {
            return true;
        }
        if(indx >= stones.size()) {
            return false;
        }
        if(visited[indx][unit]) {
            return dp[indx][unit];
        }
        bool isReached = false;
        if(stoneMap[stones[indx] + unit + 1]) {
            int nextIndx = stoneMap[stones[indx] + unit + 1] - 1;
            isReached |= canCross(nextIndx, unit + 1, stones, stoneMap, visited, dp);
        }
        if(!isReached and unit > 0 and stoneMap[stones[indx] + unit]) {
            int nextIndx = stoneMap[stones[indx] + unit] - 1;
            isReached |= canCross(nextIndx, unit, stones, stoneMap, visited, dp);
        }
        if(!isReached and unit - 1 > 0 and stoneMap[stones[indx] + unit - 1]) {
            int nextIndx = stoneMap[stones[indx] + unit - 1] - 1;
            isReached |= canCross(nextIndx, unit - 1, stones, stoneMap, visited, dp);
        }
        visited[indx][unit] = true;
        return dp[indx][unit] = isReached;
    }
    
 public:   
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        const int MAX_UNIT = 100;
        vector<vector<bool>> dp(n, vector<bool>(MAX_UNIT, false));
        vector<vector<bool>> visited(n, vector<bool>(MAX_UNIT, false));
        unordered_map<int, int> stoneMap;
        for(int i = 1; i <= n; ++i) {
            stoneMap[stones[i - 1]] = i;
        }
        return canCross(0, 0, stones, stoneMap, visited, dp);
    }
};