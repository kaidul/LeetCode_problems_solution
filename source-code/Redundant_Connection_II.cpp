class Solution {
    int find(int u, vector<int>& parent) {
        return parent[u] != u ? parent[u] = find(parent[u], parent) : parent[u];
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> candidateA{-1, -1}, candidateB{-1, -1}; // edge pair pointing two parents for same node i.e. [2, 1], [3, 1]
        vector<int> parent(n + 1, 0);
        for(vector<int>& edge: edges) {
            if(parent[edge[1]] == 0) {
                parent[edge[1]] = edge[0];
            } else {
                candidateA = vector<int>{parent[edge[1]], edge[1]};
                candidateB = edge;
                edge[1] = 0;
            }
        }
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            if(v == 0) {
                continue;
            }
            u = find(u, parent), v = find(v, parent);
            if(u == v) {
                if(candidateA[0] == -1) {
                    return edges[i];    
                }
                return candidateA;
            }
            parent[v] = u;
        }
        return candidateB;
    }
};