class MagicDictionary {
    class trie {
        class trieNode {
        public:
            bool mark;
            unordered_map<char, trieNode*> childrenMap;
            trieNode(): mark(false) {
                childrenMap = unordered_map<char, trieNode*>();
            }
            ~trieNode() {
                for(auto it = childrenMap.begin(); it != childrenMap.end(); ++it) {
                    delete it->second;
                }
                childrenMap = unordered_map<char, trieNode*>();
            }
        };
        
        bool search(int indx, int ignored, string const& key, trieNode* pCrawl) {
            if(ignored > 1) {
                return false;
            }
            if(indx == key.length() - 1) {
                if(ignored == 0) {
                    for(auto it = pCrawl->childrenMap.begin(); it != pCrawl->childrenMap.end(); ++it) {
                        if(it->first != key[indx] and it->second->mark) {
                            return true;
                        }
                    }
                    return false;
                }
                return pCrawl->childrenMap.find(key[indx]) != pCrawl->childrenMap.end() 
                        and pCrawl->childrenMap[key[indx]]->mark
                        and ignored == 1;
            }
            for(auto it = pCrawl->childrenMap.begin(); it != pCrawl->childrenMap.end(); ++it) {
                if(search(indx + 1, ignored + (it->first != key[indx]), key, it->second)) {
                    return true;
                }
            }
            return false;
        }
        
        trieNode* root;
        
    public:
        trie(): root(new trieNode()) {
        }
        
        ~trie() {
            // delete root;
            root = nullptr;
        }
        
        void insert(string const& key) {
            trieNode* pCrawl = root;
            for(int i = 0; i < key.length(); i++) {
                if(pCrawl->childrenMap.find(key[i]) == pCrawl->childrenMap.end()) {
                    pCrawl->childrenMap[key[i]] = new trieNode();
                }
                pCrawl = pCrawl->childrenMap[key[i]];
            }
            pCrawl->mark = true;
        }
        
        bool search(string const& key) {
            trieNode* pCrawl = root;
            return search(0, 0, key, root);
        }
        
    };
public:
    trie Trie;
    /** Initialize your data structure here. */
    MagicDictionary() {
        Trie = trie();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(string const& key: dict) {
            Trie.insert(key);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return Trie.search(word);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */