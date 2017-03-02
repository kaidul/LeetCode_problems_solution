// bit manipulation
class Solution {
    string getAbbr(string& word, int mask) {
        int n = word.length();
        string abbr = "";
        int right = 0;
        while(right < n) {
            if(mask & (1 << right)) {
                int left = right;
                while(mask & (1 << right)) {
                    ++right;
                }
                int len = right - left;
                abbr += to_string(len);
            } else {
                abbr += word[right++];
            }
        }
        return abbr;
    }
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        int n = word.length();
        int Max = (1 << n);
        for(int i = 0; i < Max; ++i) {
            string abbr = getAbbr(word, i);
            result.push_back(abbr);
        }
        return result;
    }
};

// backtracking
class Solution {
    void generateAbbreviationsRecur(string word, unordered_set<string>& visited, vector<string>& result) {
        if(visited.find(word) != visited.end()) {
            return;
        }
        visited.insert(word);
        result.push_back(word);
        bool proceed = false; // variable for early prunning
        for(int i = 1, n = word.size(); i <= n; ++i) {
            string sDigit = to_string(i);
            for(int j = 0; j + i - 1 < n; ++j) {
                bool isValidPrefix = (j == 0 or (j > 0 and !isdigit(word[j - 1])));
                bool isValidSuffix = (j + i - 1 == n - 1 or (j + i - 1 < n - 1 and !isdigit(word[j + i])));
                bool isValidMid = true;
                for(int k = j; k < j + i; ++k) {
                    if(isdigit(word[k])) {
                        isValidMid = false;
                        break;    
                    }
                }
                if(isValidMid and isValidPrefix and isValidSuffix) {
                    string abbr = word.substr(0, j) + sDigit + word.substr(j + i);
                    generateAbbreviationsRecur(abbr, visited, result);
                    proceed = true;
                }
            }
            if(!proceed) break;
            proceed = false;
        }    
    }
    
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        unordered_set<string> visited;
        generateAbbreviationsRecur(word, visited, result);
        return result;
    }
};