class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        if(n == 0 or edges.empty()) return n;
        vector<vector<int>> adj(n, vector<int>());
        for(int i = 0; i < edges.size(); ++i) {
            int u = edges[i].first;
            int v = edges[i].second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        queue<int> Q;
        int cnt = 0;
        for(int node = 0; node < n; ++node) {
            if(!visited[node]) {
                ++cnt;
                Q.push(node);
                visited[node] = true;
                
                while(!Q.empty()) {
                    int u = Q.front();
                    Q.pop();
                    for(int i = 0; i < (int)adj[u].size(); ++i) {
                        int v = adj[u][i];
                        if(!visited[v]) {
                            visited[v] = true;
                            Q.push(v);    
                        }
                    }
                }
            }
        }
        return cnt;
    }
};