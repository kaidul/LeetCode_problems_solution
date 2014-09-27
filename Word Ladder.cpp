class Solution {
public:
    bool isNextState(string lhs, string rhs) {
        bool flag = false;
        for(int i = 0; i < lhs.length(); ++i) {
            if(lhs[i] != rhs[i]) {
                if(flag) return false;
                flag = true;
            }
        }
        return true;
    }

    void findDict(string s, vector<string> &nexts, unordered_set<string> &dict) {
        for(int i = 0; i < s.length(); ++i) {
            string str = s;
            for(char j = 'a'; j <= 'z'; ++j) {
                str[i] = j;
                if(dict.find(str) != dict.end()) {
                    nexts.push_back(str);
                }
            }
        }
    }

    // DFS
    int ladderLengthUtils(string end, string curr, int depth, unordered_set <string> &dict, unordered_map <string, bool> &visited) {
        if(curr == end) return depth;
        if(isNextState(curr, end)) return depth + 1;
        int Min = numeric_limits<int>::max();
        for(unordered_set <string>::iterator it = dict.begin(); it != dict.end(); ++it) {
            if(!visited[*it]) {
                if(isNextState(curr, *it)) {
                    visited[*it] = true;
                    Min = min(ladderLengthUtils(end, *it, depth + 1, dict, visited), Min);
                    visited[*it] = false;
                }
            }
        }
        return Min;
    }

    // double BFS - works faster. here both start and end states are known, so double bfs suits better
    int ladderLengthDoubleBFS(string start, string end, unordered_set<string> &dict) {
        if (isNextState(start, end)) {
            return 2;
        }

        queue<pair<string, int> > Q, rQ;
        unordered_map <string, bool> visited, rVisited;

        int level = 1, rlevel = 1;
        Q.push(make_pair(start, 1));
        rQ.push(make_pair(end, 1));

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

        return 0;
    }

    int ladderLength(string start, string end, unordered_set<string> &dict) {
        
        // return ladderLengthDoubleBFS(start, end, dict);

        if(dict.size() == 0) {
            if( isNextState(start, end) )
                return 2;
        }
        unordered_map <string, bool> visited;
        /* DFS - TLE
        int ret = ladderLengthUtils(end, start, 1, dict, visited);
        if(ret == numeric_limits<int>::max())
            return 0;
        return ret;
        */
        queue <pair<string, int> > Q;
        Q.push(make_pair(start, 1));
        visited[start] = true;
        while(!Q.empty()) {
            pair<string, int> pop = Q.front();
            string curr = pop.first;
            int depth = pop.second;
            Q.pop();

            if(curr == end) return depth;
            if(isNextState(curr, end)) return depth + 1;

            /*
            for(unordered_set <string>::iterator it = dict.begin(); it != dict.end(); ++it) {
                if(!visited[*it]) {
                    if(isNextState(curr, *it)) {
                        visited[*it] = true;
                        Q.push(make_pair(*it, depth + 1));
                    }
                }
            }
            */

            vector <string> nexts;
            findDict(curr, nexts, dict);
            for (vector <string>::iterator it = nexts.begin(); it != nexts.end(); it++) {
                if (!visited[*it]) {
                    visited[*it] = true;
                    Q.push(make_pair(*it, depth + 1));
                }
            }

        }
        return 0;
    }
};