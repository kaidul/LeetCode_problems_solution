class Solution {
    void allPathsSourceTarget(int curr, 
                              int const dest, 
                              vector<vector<int>> const& graph, 
                              vector<bool>& visited, 
                              vector<int>& solution, vector<vector<int>>& result) {
        if(curr == dest) {
            result.push_back(solution);
            return;
        }
        for(int i = 0; i < graph[curr].size(); i++) {
            int neigh = graph[curr][i];
            if(!visited[neigh]) {
                visited[neigh] = true;
                solution.push_back(neigh);
                allPathsSourceTarget(neigh, dest, graph, visited, solution, result);
                visited[neigh] = false;
                solution.pop_back();
            }
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = (int) graph.size();
        int src = 0, dest = n - 1;
        vector<vector<int>> result;
        vector<bool> visited(n, false);
        vector<int> solution;
        solution.push_back(src);
        visited[src] = true;
        allPathsSourceTarget(src, dest, graph, visited, solution, result);
        
        return result;
    }
};