class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map <char, string> Map;
        unordered_map<string, char> rMap;
        vector<string> words;
        string word;
        stringstream SS(str);
        while(getline(SS, word, ' ')) {
            words.push_back(word);
        }
        if(pattern.length() != words.size()) {
            return false;
        }
        for(int i = 0; i < pattern.length(); ++i) {
            if(Map.find(pattern[i]) != Map.end()) {
                if(Map[pattern[i]] != words[i]) {
                    return false;
                }
            } else if(rMap.find(words[i]) != rMap.end()) {
                return false;
            }
            Map[pattern[i]] = words[i];
            rMap[words[i]] = pattern[i];
        }
        return true;
    }
};