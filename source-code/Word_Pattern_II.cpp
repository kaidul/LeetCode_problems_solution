class Solution {
    bool wordPatternMatchRecur(int i, string const& pattern, int offset, string const& str, unordered_map<char, string>& Map, unordered_map<string, char>& rMap) {
        if(i == pattern.length() and offset == str.length()) {
            return true;
        }
        if(i > pattern.length() or offset > str.length()) {
            return false;
        }
        char key = pattern[i];
        if(Map.find(key) != Map.end()) {
            int len = Map[key].length();
            string value = str.substr(offset, len);
            if(value != Map[key]) {
                return false;
            }
            return wordPatternMatchRecur(i + 1, pattern, offset + len, str, Map, rMap);
        }
        
        for(int k = offset; k < (int) str.length(); ++k) {
            string value = str.substr(offset, k - offset + 1);
            if(rMap.find(value) == rMap.end()) {
                Map[key] = value;
                rMap[value] = key;
                if(wordPatternMatchRecur(i + 1, pattern, k + 1, str, Map, rMap)) {
                    return true;
                }
                Map.erase(key);
                rMap.erase(value);
            }
        }
        return false;
    }
    
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map <char, string> Map;
        unordered_map <string, char> rMap;
        return wordPatternMatchRecur(0, pattern, 0, str, Map, rMap);
    }
};