class Solution {
public:
#define MAX 26
    // works but visit same node twice in case like (1->2, 1->3, 3->2)
    bool hasLoop(int node, vector<vector<int>>& adj, vector<bool>& marked) {
        if(marked[node]) {
            return true;
        }
        marked[node] = true;
        for(int i = 0; i < (int)adj[node].size(); ++i) {
            int neigh = adj[node][i];
            if(hasLoop(neigh, adj, marked)) {
                return true;
            }
        }
        marked[node] = false;
        return false;
    }
    
#define WHITE   0
#define GRAY    1
#define BLACK   2    
    bool hasLoop2(int node, vector<vector<int>>& adj, vector<int>& color) {
        if(color[node] == BLACK) {
            return false;
        }
        if(color[node] == GRAY) {
            return true;
        }
        color[node] = GRAY;
        for(int i = 0; i < (int)adj[node].size(); ++i) {
            int neigh = adj[node][i];
            if(hasLoop2(neigh, adj, color)) {
                return true;
            }
        }
        color[node] = BLACK;
        
        return false;
    }

    void topSortUtil(int node, vector<vector<int>>& adj, vector<bool>& visited, string& result) {
        visited[node] = true;
        for(int i = 0; i < (int)adj[node].size(); ++i) {
            if(!visited[adj[node][i]]) {
                topSortUtil(adj[node][i], adj, visited, result);
            }
        }
        result += ('a' + node);
    }
    string topSort(vector<bool>& visited, vector<vector<int>>& adj) {
        string result;
        for(int i = 0; i < MAX; ++i) {
            if(!visited[i]) {
                topSortUtil(i, adj, visited, result);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }

    string alienOrder(vector<string>& words) {
        string order;
        vector<vector<int>> adj(MAX, vector<int>());
        vector<bool> visited(MAX, true);
        for(int i = 0;  i < words.size(); ++i) {
            for(int k = 0; k < words[i].length(); ++k) {
               visited[words[i][k] - 'a'] = false;
            }
        }
        for(int i = 0; i < words.size() - 1; ++i) {
            string word1 = words[i];
            string word2 = words[i + 1];
            for(int j = 0, n = min(word1.length(), word2.length()); j < n; ++j) {
                if(word1[j] != word2[j]) {
                    adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                    break;
                }
            }
        }
#if 0
        vector<bool> marked(MAX, false);
        for(int i = 0; i < MAX; ++i) {
            if(!visited[i]) {
                if(hasLoop(i, adj, marked)) {
                    return order;
                }
            }
        }
#endif
        
        vector<int> color(MAX, WHITE);
        for(int i = 0; i < MAX; ++i) {
            if(!visited[i]) {
                if(hasLoop2(i, adj, color)) {
                    return order;
                }
            }
        }
        
        order = topSort(visited, adj);
        return order;
    }
};