class Solution {
    enum Color {
        WHITE = 1,
        BLACK = 2
    };
    
    bool isBipartite(int node, vector<vector<int>> const& graph, vector<int>& color) {
        for(int i = 0; i < graph[node].size(); i++) {
            int neigh = graph[node][i];
            if(color[neigh] and color[neigh] == color[node]) {
                return false;
            }
            if(!color[neigh]) {
                color[neigh] = (color[node] == WHITE ? BLACK : WHITE);
                if(!isBipartite(neigh, graph, color)) {
                    return false;
                }
            }
        }
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = (int)graph.size();
        vector<int> color(n, 0);
        for(int node = 0; node < n; node++) {
            if(!color[node]) {
                color[node] = WHITE;
                if(!isBipartite(node, graph, color)) {
                    return false;
                }
            }   
        }
        return true;
    }
};
