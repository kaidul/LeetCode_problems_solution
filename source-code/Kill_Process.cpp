class Solution {
    void killProcess(int kill, unordered_map<int, vector<int>>& adj, vector<int>& processes) {
        for(auto pidIter = adj[kill].begin(); pidIter != adj[kill].end(); ++pidIter) {
            killProcess(*pidIter, adj, processes);
        }
        processes.push_back(kill);
    }
    
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < pid.size(); i++) {
            if(adj.find(ppid[i]) == adj.end()) {
                adj[ppid[i]] = vector<int>();
            }
            adj[ppid[i]].push_back(pid[i]);
        }
        vector<int> processes;
        killProcess(kill, adj, processes);
        
        return processes;
    }
};
