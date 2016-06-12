class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> result;
        unordered_set<int> adj[n];
        for(int i = 0; i < (int)edges.size(); ++i) {
            adj[edges[i].first].insert(edges[i].second);
            adj[edges[i].second].insert(edges[i].first);
        }
        queue<int> Q; 
        for(int i = 0; i < n; ++i) {
            if(adj[i].size() == 1) {
                Q.push(i);
            }
        }
        int rmvd = 0;
        while(!Q.empty()) {
            if(rmvd >= n - 2) {
                while(!Q.empty()) {
                    result.push_back(Q.front());
                    Q.pop();
                }
                break;
            }
            for(int i = 0, n = (int)Q.size(); i < n; ++i) {
                int node = Q.front();
                for(auto it = adj[node].begin(); it != adj[node].end(); ++it) {
                    int neigh = *it;
                    adj[neigh].erase(node);
                    if((int)adj[neigh].size() == 1) {
                        Q.push(neigh);
                    }
                }
                Q.pop();
                ++rmvd;
            }
        }
        if(edges.empty() and n == 1) {
            result.push_back(0);
        }
        return result;
    }
};