class Solution {
public:
/*
    const static int SIZE = 30;
    const static int NOT_FOUND = -1;
    struct trieNode {
        int mark;
        trieNode* children[SIZE];
        trieNode(): mark(NOT_FOUND) {
            for(int i = 0; i < SIZE; ++i) {
                children[i] = nullptr;
            }
        }
    };
    struct trie {
        trieNode* root;
        trie(): root(new trieNode()) {
        }
        
        void insert(string key, int id) {
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
        
        int find(string key) {
            trieNode *pCrawl = root;
            for(int i = 0; i < key.length(); ++i) {
                int indx = key[i] - 'a';
                if(!pCrawl->children[indx]) {
                    return NOT_FOUND;
                }
                pCrawl = pCrawl->children[indx];
            }
            return pCrawl->mark;
        }
        
    };
    */
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int n = s.length();
        int m = words.size();
        if(m == 0) {
            return result;
        }
        int len = words[0].length();
        /*
        if(n < len) {
            return result;
        }
        trie Trie;
        for(int i = 0; i < n - len + 1; ++i) {
            Trie.insert(s.substr(i, len), i);
        }
        for(int i = 0; i < m; ++i) {
            int indx = Trie.find(words[i]);
            if(indx != NOT_FOUND) {
                result.push_back(indx);
            }
        }
        */
        unordered_map <string, int> freq;
        for(int i = 0; i < m; ++i) {
            freq[words[i]]++;
        }
        for(int i = 0; i <= n - m * len + 1; ++i) {
            unordered_map <string, int> freq2;
            int j = 0;
            while(j < m) {
                string subs = s.substr(i + j * len, len);
                if(freq.find(subs) == freq.end()) {
                    break;
                } else {
                    freq2[subs]++;
                    if(freq2[subs] > freq[subs]) {
                        break;
                    }
                    ++j;
                }
            }
            if(j == m) {
                result.push_back(i);
            }
        }
        return result;
    }
};