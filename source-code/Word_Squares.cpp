class Solution {
#define MAX 26
    
    struct Trie {
        
        struct trieNode {
            
            int mark;
            trieNode* children[MAX];
            
            trieNode(): mark(0) {
                for(int i = 0; i < MAX; ++i) {
                    children[i] = nullptr;
                }
            }
            
            ~trieNode() {
                for(int i = 0; i < MAX; ++i) {
                    delete children[i];
                    children[i] = nullptr;
                }
            }
        };
        
        trieNode* root;
        Trie(): root(new trieNode()) {}
        ~Trie() {
            delete root;
        }
        
        void insert(string const& key, int id) {
            
            trieNode* pCrawl = root;
            
            for(int i = 0; i < key.length(); ++i) {
                int indx = key[i] - 'a';
                if(!pCrawl->children[indx]) {
                    pCrawl->children[indx] = new trieNode();
                }
                pCrawl = pCrawl->children[indx];
            }
            
            pCrawl->mark = id;
        }
        
        void searchUtil(trieNode* root, int depth, vector<int>& ids) {
            
            if(depth == 0) {
                if(root->mark) {
                    ids.push_back(root->mark);
                }
                return;
            }
            
            for(int i = 0; i < MAX; ++i) {
                if(root->children[i]) {
                    searchUtil(root->children[i], depth - 1, ids);
                }
            }
        }
        
        void search(string const& prefix, int len, vector<int>& ids) {
            
            trieNode *pCrawl = root;
            
            for(int i = 0; i < prefix.length(); ++i) {
                int indx = prefix[i] - 'a';
                if(!pCrawl->children[indx]) {
                    return;
                }
                pCrawl = pCrawl->children[indx];
            }
            
            searchUtil(pCrawl, len - prefix.length(), ids);
        }
    };
    
    void wordSquaresBcktk(int k, const int len, vector<string>& solution, vector<string>& words, Trie* trie, vector<vector<string>>& result) {
        if(k == 0) {
            result.push_back(solution);
            return;
        }
        string prefix = "";
        int indx = solution.size();
        for(int i = 0; i < indx; ++i) {
            prefix += solution[i][indx];
        }
        vector<int> ids;
        trie->search(prefix, len, ids);
        for(int i = 0; i < ids.size(); ++i) {
            solution.push_back(words[ids[i] - 1]);
            wordSquaresBcktk(k - 1, len, solution, words, trie, result);
            solution.pop_back();
        }
    }
    
    void wordSquaresUtil(int k, int len, vector<string>& words, Trie* trie, vector<vector<string>>& result) {
        vector<string> solution;
        for(int i = 0; i < words.size(); ++i) {
            solution.push_back(words[i]);
            wordSquaresBcktk(k - 1, len, solution, words, trie, result);
            solution.pop_back();
        }
    }
    
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words.size();
        vector<vector<string>> result;
        if(n == 0) return result;
        int len = words[0].size();
        
        Trie* trie = new Trie();
        for(int i = 0; i < n; ++i) {
            trie->insert(words[i], i + 1);
        }
        
        wordSquaresUtil(len, len, words, trie, result);
        
        delete trie;
        
        return result;
    }
};