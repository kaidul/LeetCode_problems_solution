class Solution {
    class trieNode {
    public:
        unordered_map<char, trieNode*> children;
        trieNode() {
        }
        ~trieNode() {
            auto node = children.begin();
            while(node != children.end()) {
                delete node->second;
                node = children.erase(node);
            }
        }
    };
    
    typedef multimap<trieNode*, int>::iterator mapIterator;
    
    class trie {
    public:
        trieNode* root;
        trie(): root(new trieNode()) {
        }
        ~trie() {
            delete root;
        }
        
        void insert(string& key, int id, multimap<trieNode*, int>& Map) {
            if(key.empty()) return;
            int n = (int)key.length();
            trieNode* pCrawl = root;
            
            for(int i = 0; i < n; ++i) {
                if(pCrawl->children.find(key[i]) == pCrawl->children.end()) {
                    pCrawl->children[key[i]] = new trieNode();
                }
                pCrawl = pCrawl->children[key[i]];
            }
            Map.insert({pCrawl, id});
        }
        
        void queryUtils(int id, trieNode* pCrawl, string& word, multimap<trieNode*, int>& Map, vector<vector<int>>& result) {
            
            for(auto node = pCrawl->children.begin(); node != pCrawl->children.end(); ++node) {
                pair<mapIterator, mapIterator> range = Map.equal_range(node->second);
                for(auto it = range.first; it != range.second; ++it) {
                    if(it->second != id) {
                        int id2 = it->second;
                        if(isPalindrome(word, 0, (int)word.length() - 1)) {
                            result.push_back({id2, id});
                        }
                    }
                }
                word.push_back(node->first);
                queryUtils(id, node->second, word, Map, result);
                word.pop_back();
            }
        }
        
        void query(string& key, int id, multimap<trieNode*, int>& Map, vector<vector<int>>& result) {
            if(key.empty()) return;
            int n = (int)key.length();
            trieNode* pCrawl = root;
            
            for(int i = n - 1; i >= 0; --i) {
                if(pCrawl->children.find(key[i]) == pCrawl->children.end()) {
                    return;
                }
                pCrawl = pCrawl->children[key[i]];
                pair<mapIterator, mapIterator> range = Map.equal_range(pCrawl);
                if(isPalindrome(key, 0, i - 1)) {
                    for(auto it = range.first; it != range.second; ++it) {
                        if(it->second != id) {
                            result.push_back(vector<int>{it->second, id});
                        }
                    }
                }
            }
            string word = "";
            queryUtils(id, pCrawl, word, Map, result);
        }
        
        bool isPalindrome(string& s, int left, int right) {
            while(left < right) {
                if(s[left++] != s[right--]) {
                    return false;
                }
            }
            return true;
        }
        
    };
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        if(words.empty()) return result;
        multimap<trieNode*, int> Map;
        int n = (int)words.size();
        trie* tree = new trie();
        for(int i = 0; i < n; ++i) {
            tree->insert(words[i], i, Map);
        }
        for(int i = 0; i < n; ++i) {
            tree->query(words[i], i, Map, result);
        }
        
        delete tree;
        
        return result;
    }
};