class Solution {
public:
    void letterCombinations(string digits, string str, unordered_map <char, vector<char> >& Map, vector<string>& result) {
        if(digits.empty()) {
            if(!str.empty()) 
                result.push_back(str);
            return;
        }
        vector<char> chars = Map[digits[0]];
        for(int i = 0; i < chars.size(); ++i) {
            letterCombinations(digits.substr(1), str + chars[i], Map, result);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        unordered_map <char, vector<char> > Map;
        int n = 2;
        vector<char> chars;
        for(char ch = 'a'; ch <= 'z'; ++ch) {
            chars.push_back(ch);
            ch++; chars.push_back(ch);
            ch++; chars.push_back(ch);
            if(ch == 'y' || ch == 'r') { ch++; chars.push_back(ch); }
            Map[char(n + '0')] = chars;
            chars.clear();
            n++;
        }
        vector<string> result;
        letterCombinations(digits, "", Map, result);
        return result;
    }
};