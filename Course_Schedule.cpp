class Solution {
public:
    bool hasCycle(int course, vector<vector<int> >& adj, vector<bool>& visited, vector<bool>& recursionStack) {
        visited[course] = true;
        recursionStack[course] = true;
        for(int i = 0; i < (int)adj[course].size(); ++i) {
            if(!visited[adj[course][i]]) {
                if(hasCycle(adj[course][i], adj, visited, recursionStack)) {
                    return true;
                }
            } else if(recursionStack[adj[course][i]]) {
                return true;
            }
        }
        recursionStack[course] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       if(numCourses < 1) return true;
       vector<vector<int> > adj;
       adj.resize(numCourses);
       int edges = prerequisites.size();
       for(int i = 0; i < edges; ++i) {
           int u = prerequisites[i][0];
           int v = prerequisites[i][1];
           adj[u].push_back(v);
       }
       vector<bool> visited(numCourses, false);
       vector<bool> recursionStack(numCourses, false);
       
       for(int course = 0; course < numCourses; ++course) {
           if(!visited[course]) {
               if(hasCycle(course, adj, visited, recursionStack))
                    return false;
           }
       }
       return true;
    }
};