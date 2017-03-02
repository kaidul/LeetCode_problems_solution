class TrieNode {
public:
    bool mark;
    TrieNode* children[26];
    // Initialize your data structure here.
    TrieNode(): mark(false) {
        for(int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        int n = s.length();
        TrieNode *pCrawl = root;
        for(int i = 0; i < n; ++i) {
            int ch = s[i] - 'a';
            if(!pCrawl->children[ch]) {
                pCrawl->children[ch] = new TrieNode();
            }
            pCrawl = pCrawl->children[ch];
        }
        pCrawl->mark = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        int n = key.length();
        TrieNode* pCrawl = root;
        for(int i = 0; i < n; ++i) {
            int ch = key[i] - 'a';
            if(!pCrawl->children[ch]) {
                return false;
            }
            pCrawl = pCrawl->children[ch];
        }
        return pCrawl->mark == true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int n = prefix.length();
        TrieNode* pCrawl = root;
        for(int i = 0; i < n; ++i) {
            int ch = prefix[i] - 'a';
            if(!pCrawl->children[ch]) {
                return false;
            }
            pCrawl = pCrawl->children[ch];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");