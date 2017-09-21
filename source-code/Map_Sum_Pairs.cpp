class MapSum {
    class Trie {
        class trieNode {
        public:
            int value;
            int sum;
            unordered_map<char, trieNode*> children;
            trieNode(): value(0), sum(0) {
                children = unordered_map<char, trieNode*>();
            }
            trieNode(int value): value(value), sum(value) {
                children = unordered_map<char, trieNode*>();
            }
        };
        
        int insert(int indx, string const& key, const int value, trieNode* pCrawl) {
            if(indx == key.length() - 1) {
                if(pCrawl->children.find(key[indx]) == pCrawl->children.end()) {
                    pCrawl->children[key[indx]] = new trieNode(value);
                    return value;
                }
                int oldValue = pCrawl->children[key[indx]]->value;
                pCrawl->children[key[indx]]->value = value;
                pCrawl->children[key[indx]]->sum += value;
                pCrawl->children[key[indx]]->sum -= oldValue;
                return value - oldValue;    
            }
            if(pCrawl->children.find(key[indx]) == pCrawl->children.end()) {
                pCrawl->children[key[indx]] = new trieNode();
            }
            int deltaSum = insert(indx + 1, key, value, pCrawl->children[key[indx]]);
            
            pCrawl->children[key[indx]]->sum += deltaSum;
            
            return deltaSum;
        }
        
        trieNode* root;
    public:
        Trie(): root(new trieNode()) {}
        
        int query(string const& key) {
            trieNode* pCrawl = root;
            for(int i = 0; i < key.length(); i++) {
                if(pCrawl->children.find(key[i]) == pCrawl->children.end()) {
                    return 0;
                }
                pCrawl = pCrawl->children[key[i]];
            }
            return pCrawl->sum;
        }
        
        void insert(string const& key, int const value) {
            insert(0, key, value, root);
        }
    };
    Trie* trie;
public:
    /** Initialize your data structure here. */
    MapSum() {
        trie = new Trie();
    }
    
    void insert(string key, int val) {
        trie->insert(key, val);
    }
    
    int sum(string prefix) {
        return trie->query(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */