class Solution {
    
#define X first
#define Y second

public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int n = (int)equations.size();
        vector<double> result;
        if(n == 0) return result;
        unordered_map<string, vector<pair<string, double>>> adj;
        for(int i = 0; i < n; i++) {
            string u = equations[i].X;
            string v = equations[i].Y;
            double cost = values[i];
            adj[u].push_back({v, cost});
            adj[v].push_back({u, 1.0 / cost});
        }
        for(int i = 0; i < queries.size(); i++) {
            string src = queries[i].X;
            string dest = queries[i].Y;
            double value = -1.0;
            if(adj.count(src) > 0 and adj.count(dest) > 0) {
                queue<pair<string, double>> Q;
                unordered_set<string> visited;
                Q.push({src, 1.0});
                visited.insert(src);
                while(!Q.empty()) {
                    string u = Q.front().X;
                    double d = Q.front().Y;
                    Q.pop();
                    if(dest == u) {
                        value = d;
                        break;
                    }
                    for(int i = 0; i < adj[u].size(); i++) {
                        string v = adj[u][i].X;
                        double factor = adj[u][i].Y;
                        if(!visited.count(v)) {
                            Q.push({v, d * factor});
                            visited.insert(v);
                        }
                    }
                }    
            }
            result.push_back(value);
        }
        return result;
    }
};