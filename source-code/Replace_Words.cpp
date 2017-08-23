class Solution {
    class trieNode {
    public:
        int keyId;
        unordered_map<char, trieNode*> children;
        trieNode(): keyId(-1), children(unordered_map<char, trieNode*>()) {
        }
    };

    class trie {
    public:
        trieNode* root;
        trie(): root(new trieNode()) {
        }

        void insert(string& key, int keyId) {
            trieNode* pCrawl = root;
            for(int i = 0; i < key.length(); i++) {
                if(!pCrawl->children[key[i]]) {
                    pCrawl->children[key[i]] = new trieNode();
                }
                pCrawl = pCrawl->children[key[i]];
            }
            pCrawl->keyId = keyId;
        }

        int search(string& key) {
            trieNode* pCrawl = root;
            for(int i = 0; i < key.length(); i++) {
                if(!pCrawl->children[key[i]]) {
                    return -1;
                }
                pCrawl = pCrawl->children[key[i]];
                if(pCrawl->keyId >= 0) {
                    return pCrawl->keyId;
                }
            }
            return -1;
        }
    };

public:
    string replaceWords(vector<string>& dict, string sentence) {
        string resultSentence;
        unordered_map<int, string> keyIdMap;
        trie* Trie = new trie();
        for(int i = 0; i < dict.size(); i++) {
            Trie->insert(dict[i], i);
            keyIdMap[i] = dict[i];
        }
        int i = 0;
        while(i < sentence.length()) {
            int spaces = 0;
            while(i < sentence.length() and sentence[i] == ' ') {
                i++;
                ++spaces;
            }
            int start = i;
            while(i < sentence.length() and isalnum(sentence[i])) {
                i++;
            }
            string word = sentence.substr(start, i - start);
            resultSentence += string(spaces, ' ');
            int keyId = Trie->search(word);
            if(keyId >= 0) {
                string root = keyIdMap[keyId];
                resultSentence += root;    
            } else {
                resultSentence += word;
            }
            
        }
        return resultSentence;
    }
};