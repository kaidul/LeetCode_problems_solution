class Solution {
public:
    bool isAlienSorted(vector<string>& words, string seq) {
        vector<int> order(256);
        int k = 0;
        for (char ch : seq) {
            order[ch] = ++k;
        }
        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            bool equal = true;
            for (int j = 0; j < min(word1.length(), word2.length()); j++) {
                if (word1[j] == word2[j]) {
                    continue;
                }
                if (order[word1[j]] < order[word2[j]]) {
                    equal = false;
                    break;
                }
                
                return false;
            }
            if (equal and word1.length() > word2.length()) {
                return false;
            }
        }
        
        return true;
    }
};