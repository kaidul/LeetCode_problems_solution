class Solution {
    static const int MAX = 26;
    static const int dir = 4;
    const int dx[dir] = {0, -1, 0, 1};
    const int dy[dir] = {-1, 0, 1, 0};
    
    struct TrieNode {
        int id;
        TrieNode* children[MAX];
        TrieNode(): id(0) {
            for(int i = 0; i < MAX; ++i) {
                children[i] = nullptr;
            }
        }
        bool hasNext(char ch) const {
            int indx = (int)(ch - 'a');
            return (children[indx] != nullptr);
        }
        TrieNode* next(char ch) {
            int indx = (int)(ch - 'a');
            return children[indx];
        }
    };
    
    class Trie {
    public:
        Trie(): root(new TrieNode()) {}
        
        void insert(string key, int id) {
            TrieNode *pCrawl = root;
            for(int i = 0; i < key.length(); ++i) {
                int indx = (int)(key[i] - 'a');
                if(!pCrawl->children[indx]) {
                    pCrawl->children[indx] = new TrieNode();
                }
                pCrawl = pCrawl->children[indx];
            }
            pCrawl->id = id;
        }
        
        TrieNode* getRoot() const {
            return root;
        }
    private:
        TrieNode* root;
    };
    
    bool isValid(int x, int y, TrieNode* node, vector<vector<bool>> const& visited, vector<vector<char>> const& board) {
        return (x < board.size() and x >= 0 and y < board[0].size() and y >= 0 and !visited[x][y] and node->hasNext(board[x][y]));
    }
    
    void findWordsUtil(int x, int y, vector<vector<char>> const& board, 
                        unordered_map<int, string>& hash, TrieNode* node, 
                        vector<bool>& taken, vector<vector<bool>>& visited, 
                        vector<string>& result, int& found) {
        if(node->id > 0 and !taken[node->id]) {
            taken[node->id] = true;
            ++found;
            result.push_back(hash[node->id]);
        }
        visited[x][y] = true;
        for(int i = 0; i < dir; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(isValid(newX, newY, node, visited, board)) {
                findWordsUtil(newX, newY, board, hash, node->next(board[newX][newY]), taken, visited, result, found);
            }
        }
        visited[x][y] = false;
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = words.size();
        unordered_map<int, string> hash;
        Trie* trie = new Trie();
        for(int i = 0; i < n; ++i) {
            trie->insert(words[i], i + 1);
            hash[i + 1] = words[i];
        }
        vector<bool> taken(n + 1, false);
        vector<string> result;
        int found = 0;
        
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); j++) {
                if(trie->getRoot()->hasNext(board[i][j])) {
                    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                    findWordsUtil(i, j, board, hash, trie->getRoot()->next(board[i][j]), taken, visited, result, found);
                }
                if(found == n) {
                    delete trie;
                    return result;
                }
            }
        }
        delete trie;
        return result;
        
    }
};