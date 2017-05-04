class Solution {
    void dfs(int u, vector<vector<int>> const& M, vector<bool>& visited) {
        visited[u] = true;
        for(int i = 0; i < (int)M[u].size(); i++) {
            if(!M[u][i] or visited[i]) {
                continue;
            }
            dfs(i, M, visited);
            
        }
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = (int)M.size();
        vector<bool> visited(n, false);
        int circle = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                circle++;
                dfs(i, M, visited);
            }
        }
        return circle;
    }
};