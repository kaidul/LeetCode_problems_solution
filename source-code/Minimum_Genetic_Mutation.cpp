class Solution {
public:
    bool isNextState(string& start, string& end) {
        bool flag = false;
        for(int i = 0; i < start.length(); ++i) {
            if(start[i] != end[i]) {
                if(flag) return false;
                flag = true;
            }
        }
        return true;
    }
    
    void findDict(string& s, vector<string> &nexts, unordered_set<string> &dict) {
        string chars = "ACGT";
        for(int i = 0; i < s.length(); ++i) {
            string str = s;
            for(int j = 0; j < chars.length(); ++j) {
                str[i] = chars[j];
                if(dict.find(str) != dict.end()) {
                    nexts.push_back(str);
                }
            }
        }
    }

    // double BFS - works faster. here both start and end states are known, so double bfs suits better
    int minMutationDoubleBFS(string start, string end, unordered_set<string> &dict) {
        if(start == end) return 0;
        if(!dict.count(end)) {
            return -1;
        }
        if(isNextState(start, end) and dict.find(end) != dict.end())
            return 1;
        queue<pair<string, int> > Q, rQ;
        unordered_map <string, bool> visited, rVisited;

        int level = 0, rlevel = 1;
        Q.push(make_pair(start, level));
        rQ.push(make_pair(end, rlevel));

        while (!Q.empty() and !rQ.empty()) {


            if (Q.size() < rQ.size()) {
                while (!Q.empty() and Q.front().second == level) {

                    vector<string> nexts;
                    findDict(Q.front().first, nexts, dict);
                    for (auto it = nexts.begin(); it != nexts.end(); it++) {
                        if (!visited[*it]) {
                            visited[*it] = true;
                            if (rVisited[*it]) {
                                return Q.front().second + rQ.back().second;
                            }
                            Q.push(make_pair(*it, level + 1));
                        }
                    }
                    Q.pop();
                }
                level++;
            } else {

                while (!rQ.empty() and rQ.front().second == rlevel) {

                    vector<string> nexts;
                    findDict(rQ.front().first, nexts, dict);
                    for (auto it = nexts.begin(); it != nexts.end(); it++) {
                        if (!rVisited[*it]) {
                            rVisited[*it] = true;
                            if (visited[*it]) {
                                return rQ.front().second + Q.back().second;
                            }
                            rQ.push(make_pair(*it, rlevel + 1));
                        }
                    }
                    rQ.pop();
                }
                rlevel++;
            }
        }

        return -1;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        return minMutationDoubleBFS(start, end, dict);
    }
};