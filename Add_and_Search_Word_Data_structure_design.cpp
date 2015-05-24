class WordDictionary {
public:
    WordDictionary(): root(new Node()) {
        
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        int len = word.length();
        Node* pCrawl = root;
        for(int i = 0; i < len; ++i) {
            int indx = (int) (word[i] - 'a');
            if(!pCrawl->children[indx]) {
                pCrawl->children[indx] = new Node();
            }
            pCrawl = pCrawl->children[indx];
        }
        pCrawl->mark = true;
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        Node *pCrawl = root;
        return searchUtil(word, pCrawl);
    }
    
private:
    const static int SIZE = 30;
    struct Node {
        bool mark;
        Node *children[SIZE];
        Node(): mark(false) {
            for(int i = 0; i < SIZE; ++i) {
                children[i] = nullptr;
            }
        }
    };
    Node *root = nullptr;
    
    bool searchUtil(string word, Node* pCrawl) {
        int len = word.length();
        for(int i = 0; i < len; ++i) {
            int indx = (int) (word[i] - 'a');
            if(word[i] == '.') {
                bool found = false;
                for(int k = 0; k < SIZE; ++k) {
                    if(pCrawl->children[k]) {
                        if(searchUtil(word.substr(i + 1), pCrawl->children[k])) {
                            return true;    
                        }
                    }
                }
                return false;
            }
            
            if(!pCrawl->children[indx]) {
                return false;
            }
            pCrawl = pCrawl->children[indx];
        }
        return pCrawl->mark == true;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");