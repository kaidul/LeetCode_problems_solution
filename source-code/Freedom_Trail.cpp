class Solution {
    int findRotateSteps(int i, string const& ring, int j, string const& key, unordered_map<char, vector<int>>& pos, vector<vector<int>>& dp) {
        if(j == key.length()) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ret = INT_MAX;
        vector<int>& nextPos = pos[key[j]];
        for(int k = 0, n = (int)nextPos.size(); k < n; k++) {
            int diff = abs(nextPos[k] - i);
            ret = min(ret, 1 + min(diff, (int)ring.length() - diff) + findRotateSteps(nextPos[k], ring, j + 1, key, pos, dp));
        }
        return dp[i][j] = ret;
    }
public:
    int findRotateSteps(string ring, string key) {
        int n = (int)ring.length();
        int m = (int)key.length();
        unordered_map<char, vector<int>> pos;
        for(int i = 0; i < n; i++) {
            pos[ring[i]].push_back(i);
        }
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return findRotateSteps(0, ring, 0, key, pos, dp);
    }
};