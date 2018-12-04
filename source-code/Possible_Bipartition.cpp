class Solution {
    enum Color {
      NONE, WHITE, BLACK
    };
    bool isBipartite(int node, vector<vector<int>>& graph, vector<int>& color) {
        for(int i = 0; i < (int)graph[node].size(); i++) {
            int neigh = graph[node][i];
            if(color[neigh] == color[node]) {
                return false;
            }
            if(color[neigh] != NONE) {
                continue;
            }
            color[neigh] = color[node] == WHITE ? BLACK : WHITE;
            if(!isBipartite(neigh, graph, color)) {
                return false;
            }
        }
        
        return true;
    }
    
    bool isBipartite(int N, vector<vector<int>>& graph) {
        vector<int> color(N + 1, NONE);
        for(int i = 1; i <= N; i++) {
            if (color[i] == NONE) {
                color[i] = WHITE;
                if(!isBipartite(i, graph, color)) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N + 1);
        for (int i = 0; i < (int)dislikes.size(); i++) {
            int person1 = dislikes[i][0];
            int person2 = dislikes[i][1];
            graph[person1].push_back(person2);
            graph[person2].push_back(person1);
        }
        
        return isBipartite(N, graph);
    }
};