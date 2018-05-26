class Solution {
public:
    bool hasCycle(int course, vector<vector<int> >& adj, vector<bool>& visited) {
        visited[course] = true;
        for(int i = 0; i < (int)adj[course].size(); ++i) {
            if(visited[adj[course][i]]) {
                return true;
            }
            if(hasCycle(adj[course][i], adj, visited)) {
                return true;
            }
        }
        visited[course] = false;
        return false;
    }
    
    enum Color {
        WHITE, GREY, BLACK
    };
    
    bool hasCycle2(int course, vector<vector<int>> const& adj, vector<int>& color) {
        color[course] = GREY;
        for(int i = 0; i < (int)adj[course].size(); ++i) {
            int neigh = adj[course][i];
            if(color[neigh] == GREY) {
                return true;
            }
            if(color[neigh] == WHITE) {
                if(hasCycle2(neigh, adj, color)) {
                    return true;
                }
            }
        }
        color[course] = BLACK;
        
        return false;
    }
    

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(numCourses < 1) return true;
        vector<vector<int> > adj;
        adj.resize(numCourses);
        int edges = prerequisites.size();
        for(int i = 0; i < edges; ++i) {
           int u = prerequisites[i].first;
           int v = prerequisites[i].second;
           adj[u].push_back(v);
        }
        vector<bool> visited(numCourses, false);
        vector<int> color(numCourses, WHITE);
        /*
        for(int course = 0; course < numCourses; ++course) {
            if(!visited[course]) {
                if(hasCycle(course, adj, visited))
                    return false;
            }
        }
        */
        for(int course = 0; course < numCourses; ++course) {
            if(color[course] == WHITE) {
                if(hasCycle2(course, adj, color))
                    return false;
            }
        }
        return true;
    }
};