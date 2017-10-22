class AutocompleteSystem {
    class TrieNode {
    public:
        bool mark;
        int score;
        unordered_map<char, TrieNode*> childrenMap;
        TrieNode(): mark(false), score(0) {
            childrenMap = unordered_map<char, TrieNode*>();
        }
    };
    
    class Trie {
    public:
        TrieNode* root;
        
        Trie(): root(new TrieNode()) {
        }
        
        void insert(string const& key, int score = 1) {
            int n = (int)key.length();
            TrieNode* pCrawl = root;
            for(int i = 0; i < n; i++) {
                if(!pCrawl->childrenMap[key[i]]) {
                    pCrawl->childrenMap[key[i]] = new TrieNode();
                }
                pCrawl = pCrawl->childrenMap[key[i]];
            }
            pCrawl->mark = true;
            pCrawl->score += score;
        }
        
        void searchUtil(string& key, TrieNode* pCrawl, priority_queue<pair<int, string>>& pQ) {
            if(!pCrawl) { return; }
            if(pCrawl->mark) {
                pair<int, string> curr = {-pCrawl->score, key};
                if(pQ.size() < 3) {
                    pQ.push(curr);
                }
                else if(pQ.size() >= 3 and pQ.top() > curr) {
                    pQ.pop();
                    pQ.push(curr);
                }
            }
            for(auto it = pCrawl->childrenMap.begin(); it != pCrawl->childrenMap.end(); ++it) {
                key += it->first;
                searchUtil(key, it->second, pQ);
                key.pop_back();
            }
        }
        
        vector<string> search(string& searchKey, TrieNode*& pCrawl) {
            vector<string> result;
            char key = searchKey[searchKey.length() - 1]; 
            if(pCrawl->childrenMap[key]) {
                pCrawl = pCrawl->childrenMap[key];
                priority_queue<pair<int, string>> pQ;
                searchUtil(searchKey, pCrawl, pQ);
                result.resize(pQ.size());
                int i = (int)result.size() - 1;
                while(!pQ.empty()) {
                    result[i--] = pQ.top().second;
                    pQ.pop();
                }
            }
            return result;
        }
    };
    
    string queryKey;
    Trie* trie;
    TrieNode* curr;
    bool found;
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        queryKey = "";
        trie = new Trie();
        curr = trie->root;
        found = true;
        int n = (int)sentences.size();
        assert(sentences.size() == times.size());
        for(int i = 0; i < n; i++) {
            trie->insert(sentences[i], times[i]);
        }
    }
    
    vector<string> input(char c) {
        if(c == '#') {
            trie->insert(queryKey);
            queryKey = "";
            found = true;
            curr = trie->root;
            return vector<string>();
        }
        queryKey += c;
        vector<string> result;
        if(found) {
            result = trie->search(queryKey, curr);
            if(result.empty()) {
                found = false;
            }
        }
        return result;
    }
};