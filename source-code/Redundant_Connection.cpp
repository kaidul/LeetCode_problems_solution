class Solution {
    int find(int u, vector<int>& parent) {
        return parent[u] != u ? parent[u] = find(parent[u], parent) : parent[u];
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            u = find(u, parent), v = find(v, parent);
            if(u == v) {
                return edges[i];
            }
            parent[v] = u;
        }
        return vector<int>(2);
    }
};