class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<int, int> keyRow;
        string firstRow = "QWERTYUIOP";
        for(int i = 0; i < firstRow.length(); i++) {
            keyRow[firstRow[i]] = 1;    
        }
        string secondRow = "ASDFGHJKL";
        for(int i = 0; i < secondRow.length(); i++) {
            keyRow[secondRow[i]] = 2;    
        }
        string thirdRow = "ZXCVBNM";
        for(int i = 0; i < thirdRow.length(); i++) {
            keyRow[thirdRow[i]] = 3;    
        }
        vector<string> result;
        for(int i = 0; i < words.size(); i++) {
            string word = words[i];
            unordered_set<int> rows;
            for(int j = 0; j < (int)word.length(); j++) {
                rows.insert(keyRow[toupper(word[j])]);
            }
            if(rows.size() == 1) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};