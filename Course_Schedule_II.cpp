class Solution {
    const int white = 0;
    const int grey = 1;
    const int black = 2;
    
    bool hasCycle(int node, vector<vector<int>> const& adj, vector<int>& color, vector<int>& result) {
        color[node] = grey;
        for(int i = 0; i < (int)adj[node].size(); ++i) {
            int neigh = adj[node][i];
            if(color[neigh] == grey) {
                return true;
            }
            if(color[neigh] == white) {
                if(hasCycle(neigh, adj, color, result)) {
                    return true;
                }
            }
        }
        color[node] = black;
        result.push_back(node);
        return false;
    }
    
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        int edges = prerequisites.size();
        vector<vector<int>> adj;
        adj.resize(numCourses);
        for(int i = 0; i < edges; ++i) {
            int u = prerequisites[i].first;
            int v = prerequisites[i].second;
            adj[u].push_back(v);
        }
        vector<int> result;
        vector<int> color(numCourses, white);
        for(int i = 0; i < numCourses; ++i) {
            if(color[i] == white) {
                if(hasCycle(i, adj, color, result)) {
                    result = vector<int>();
                    return result;
                }
            }
        }
        return result;
    }
};