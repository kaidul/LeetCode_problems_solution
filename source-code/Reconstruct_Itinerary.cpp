class Solution {
    void dfs(string u, unordered_map<string, multiset<string>>& adj, vector<string>& result) {
        
        auto it = adj[u].begin();
        while(it != adj[u].end()) {
            string v = *it;
            adj[u].erase(it);
            dfs(v, adj, result);
            it = adj[u].begin();
        }
        
        result.push_back(u);
    }
    
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> result;
        if(tickets.empty()) return result;
        unordered_map<string, multiset<string>> adj;
        for(int i = 0; i < (int)tickets.size(); ++i) {
            string u = tickets[i].first;
            string v = tickets[i].second;
            
            adj[u].insert(v);
        }
        
        const string src = "JFK";
        dfs(src, adj, result);
        reverse(result.begin(), result.end());
        return result;
    }
};