class WordFilter {
    class Trie {
        static const int SIZE = 26;
    private:
        struct trieNode {
            int weight;
            trieNode* children[SIZE];
            trieNode(): weight(-1) {
                for(int i = 0; i < SIZE; ++i) {
                    children[i] = nullptr;
                }
            }
            ~trieNode() {
                for(int i = 0; i < SIZE; ++i) {
                    delete children[i];
                    children[i] = nullptr;
                }
            }
        };
        trieNode* root;
    public:
        Trie(): root(new trieNode()) {
        }
        
        ~Trie() {
            delete root;
            root = nullptr;
        }

        void insert(string const& key, int weight, bool reverse = false) {
            trieNode* pCrawl = root;
            if(!reverse) {
                for(int i = 0; i < key.length(); ++i) {
                    int indx = key[i] - 'a';
                    if(!pCrawl->children[indx]) {
                        pCrawl->children[indx] = new trieNode();
                    }
                    pCrawl = pCrawl->children[indx];
                }
                pCrawl->weight = weight;
                
                return;
            }
            
            for(int i = key.length() - 1; i >= 0; --i) {
                int indx = key[i] - 'a';
                if(!pCrawl->children[indx]) {
                    pCrawl->children[indx] = new trieNode();
                }
                pCrawl = pCrawl->children[indx];
            }
            pCrawl->weight = weight;
        }

        void searchUtil(trieNode* pCrawl, unordered_set<int>& prefixMatchedSet) {
            if(pCrawl->weight != -1) {
                prefixMatchedSet.insert(pCrawl->weight);
            }
            for(int i = 0; i < SIZE; i++) {
                if(pCrawl->children[i]) {
                    searchUtil(pCrawl->children[i], prefixMatchedSet);
                }
            }    
        }
        
        void search(string const& prefix, unordered_set<int>& prefixMatchedSet) {
            trieNode *pCrawl = root;
            for(int i = 0; i < prefix.length(); ++i) {
                int indx = prefix[i] - 'a';
                if(!pCrawl->children[indx]) {
                    return;
                }
                pCrawl = pCrawl->children[indx];
            }
            searchUtil(pCrawl, prefixMatchedSet);
        }
        
        int searchUtil2(trieNode* pCrawl, unordered_set<int>& prefixMatchedSet) {
            int weight = -1;
            if(pCrawl->weight != -1) {
                if(prefixMatchedSet.find(pCrawl->weight) != prefixMatchedSet.end()) {
                    weight = max(weight, pCrawl->weight);
                }
            }
            for(int i = 0; i < SIZE; i++) {
                if(pCrawl->children[i]) {
                    weight = max(weight, searchUtil2(pCrawl->children[i], prefixMatchedSet));
                }
            }
            
            return weight;
        }
        
        int search2(string const& suffix, unordered_set<int>& prefixMatchedSet) {
            trieNode *pCrawl = root;
            for(int i = suffix.length() - 1; i >= 0; --i) {
                int indx = suffix[i] - 'a';
                if(!pCrawl->children[indx]) {
                    return -1;
                }
                pCrawl = pCrawl->children[indx];
            }
            return searchUtil2(pCrawl, prefixMatchedSet);
        }
    };
    
    Trie* prefixTrie;
    Trie* suffixTrie;
public:
    WordFilter(vector<string> words) {
        prefixTrie = new Trie();
        suffixTrie = new Trie();
        for(int i = 0; i < words.size(); i++) {
            prefixTrie->insert(words[i], i);
            suffixTrie->insert(words[i], i, true);
        }
    }
    
    int f(string prefix, string suffix) {
        unordered_set<int> prefixMatchedSet;
        prefixTrie->search(prefix, prefixMatchedSet);
        return suffixTrie->search2(suffix, prefixMatchedSet);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
