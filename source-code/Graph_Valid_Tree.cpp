class Solution {
public:
    bool hasCycle(int parent, int node, vector<vector<int> >& adj, vector<bool>& visited) {
        visited[node] = true;
        bool ret = true;
        for(int i = 0; i < (int) adj[node].size(); ++i) {
            if(adj[node][i] != parent) {
                int child = adj[node][i];
                if(visited[child]) {
                    return false;
                }
                ret &= hasCycle(node, child, adj, visited);
            }
        }
        return ret;
    }
    
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int> > adj (n, vector<int>());
        for(int i = 0; i < edges.size(); ++i) {
            int u = edges[i].first;
            int v = edges[i].second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        bool isTree = hasCycle(-1, 0, adj, visited);
        
        if(isTree) for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                return false;
            }
        }
        return isTree;
    }
};