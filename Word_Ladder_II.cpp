// optimized BFS. still TLE :/
class Solution {
    struct wordNode {
        string word;
        wordNode* parent;
        int level;
        wordNode(string sWord, wordNode* pParent, int iLevel) {
            word = sWord;
            parent = pParent;
            level = iLevel;
        }
    };
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string>> result;
        wordList.insert(endWord);
        queue<wordNode*> Q;
        unordered_set<string> visited;
        Q.push(new wordNode(beginWord, nullptr, 1));
        int depth = 0;
        while(!Q.empty()) {
            wordNode* node = Q.front();
            string word = node->word;
            int currLevel = node->level;
            Q.pop();
            if(depth > 0 and currLevel > depth) {
                break;
            }
            if(word == endWord) {
                depth = currLevel;
                vector<string> path(depth);
                int indx = depth;
                path[--indx] = endWord;
                while(node->parent) {
                    path[--indx] = node->parent->word;
                    node = node->parent;
                }
                result.push_back(path);
                continue;
            }
            visited.insert(word);
            string neigh = word;
            for(int i = 0 ; i < neigh.length(); ++i) {
                char tmp = neigh[i];
                for(char ch = 'a'; ch <= 'z'; ++ch) {
                    neigh[i] = ch;
                    if(wordList.find(neigh) != wordList.end() and visited.find(neigh) == visited.end()) {
                        Q.push(new wordNode(neigh, node, currLevel + 1));
                    }
                }
                neigh[i] = tmp;
            }
        }
        return result;
    }
};
// modified BFS. still TLE :(
class Solution {
    void findAdjList(string curr, unordered_set<string>& wordList, vector<string>& neighs) {
        for(int i = 0; i < curr.length(); ++i) {
            char tmp = curr[i];
            for(char ch = 'a'; ch <= 'z'; ++ch) {
                curr[i] = ch;
                if(wordList.find(curr) != wordList.end()) {
                    neighs.push_back(curr);
                }
            }
            curr[i] = tmp;
        }
    }
    
    bool isNextState(string const& word1, string const& word2) {
        bool flag = false;
        if(word1.length() != word2.length()) return false;
        for(int i = 0; i < word1.length(); ++i) {
            if(word1[i] != word2[i]) {
                if(flag) {
                    flag = false;
                    break;
                }
                flag = true;
            }
        }
        return flag;
    }
    
    void findShortestPaths(string node, int indx, unordered_map<string, unordered_set<string>>& parents, vector<string>& solution, vector<vector<string>>& result) {
        if(parents[node].find(node) != parents[node].end()) {
            solution[indx] = node;
            result.push_back(solution);
            return;
        }
        solution[indx] = node;
        for(auto parentIter = parents[node].begin(); parentIter != parents[node].end(); ++parentIter) {
            findShortestPaths(*parentIter, indx - 1, parents, solution, result);
        }
    }
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        queue<string> Q;
        unordered_map<string, bool> visited;
        unordered_map<string, int> level;
        unordered_map<string, unordered_set<string>> parents;
        Q.push(beginWord);
        level[beginWord] = 1;
        parents[beginWord].insert(beginWord);
        int depth = INT_MAX;
        while(!Q.empty()) {
            string node = Q.front();
            visited[node] = true;
            Q.pop();
            if(level[node] > depth) {
                break;
            }
            if(level[node] == depth and node != endWord) {
                continue;    
            }
            if(isNextState(node, endWord)) {
                level[endWord] = level[node] + 1;
                parents[endWord].insert(node);
                Q.push(endWord);
                depth = level[endWord];
                continue;
            }
            vector<string> neighs;
            findAdjList(node, wordList, neighs);
            for(int i = 0; i < (int)neighs.size(); ++i) {
                string neigh = neighs[i];
                if(level[neigh] > 0) {
                    if(level[node] >= level[neigh]) {
                        continue;
                    }
                }
                if(!visited[neigh]) {
                    Q.push(neigh);
                    parents[neigh].insert(node);
                    level[neigh] = level[node] + 1;
                    if(neigh == endWord) {
                        depth = level[neigh];
                    }
                }
            }
        }
        vector<vector<string>> result;
        if(depth == INT_MAX) return result;
        vector<string> solution(depth, "");
        findShortestPaths(endWord, depth - 1, parents, solution, result);
        return result;
    }
};


// BFS + DFS TLE
class Solution {
public:
    void findAdjacents(string curr, unordered_set<string> &dict, vector<string> &nexts) {
        for(int i = 0, n = curr.length(); i < n; ++i) {
            char tmp = curr[i];
            for(char ch = 'a'; ch <= 'z'; ++ch) {
                curr[i] = ch;
                if(dict.find(curr) != dict.end()) {
                    nexts.push_back(curr);
                }
            }
            curr[i] = tmp;
        }
    }

    bool isNextState(string const& u, string const& v) {
        bool flag = false;
        for(int i = 0, n = u.length(); i < n; ++i) {
            if(u[i] != v[i] ) {
                if(flag) return false;
                flag = true;
            }
        }
        return flag;
    }

    void dfs(string curr, int depth, int limit, string end, unordered_set<string> &dict, unordered_map <string, bool> &visited, vector<string> &solution, vector<vector<string> > &result) {
        
        if(curr == end) {
            result.push_back(solution);
            return;
        }
        
        if(isNextState(curr, end) and depth < limit) {
            solution.push_back(end);
            result.push_back(solution);
            solution.pop_back();
            return;
        }
        
        if(depth == limit) return;
        
        vector<string> nexts;
        findAdjacents(curr, dict, nexts);
        
        for(auto it = nexts.begin(); it != nexts.end(); ++it) {
            string neigh = (*it);
            if(!visited[neigh]) {
                visited[neigh] = true;
                solution.push_back(neigh);
                dfs(neigh, depth + 1, limit, end, dict, visited, solution, result);
                visited[neigh] = false;
                solution.pop_back();
            }
        }
    }

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > result;
        int shortestPathLen = -1;
    
        unordered_map <string, bool> visited;
        queue <pair<string, int> > Q;
        Q.push(make_pair(start, 1));
        visited[start] = true;
        
        while(!Q.empty()) {
            string curr = Q.front().first;
            int level = Q.front().second;
            Q.pop();
            if( isNextState(curr, end) ) {
                shortestPathLen = level + 1;
                break;
            }
            if(curr == end) {
                shortestPathLen = level;
                break;
            }
            vector<string> nexts;
            findAdjacents(curr, dict, nexts);
            for(auto it = nexts.begin(); it != nexts.end(); ++it) {
                if(!visited[*it]) {
                    visited[*it] = true;
                    Q.push(make_pair(*it, level + 1));
                }
            }
        }
        if(shortestPathLen == -1) {
            return result;
        }
        vector<string> solution;
        visited = unordered_map <string, bool> ();
        visited[start] = true;
        solution.push_back(start);
        dfs(start, 1, shortestPathLen, end, dict, visited, solution, result);
        return result;
    }
};