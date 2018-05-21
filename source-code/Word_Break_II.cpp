class Solution {
    bool isPossible(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n, false); 
        dp[0] = true;
        for(int i = 0; i < n; ++i) {
            if(dp[i]) {
                for(string const& word : wordDict) {
                    int len = word.length();
                    if(i + len <= n and !dp[i + len] and s.substr(i, len) == word) {
                        dp[i + len] = true;
                    } 
                }
            }
        }
        return dp[n];
    }
    
    void wordBreak(int indx, string const& s, vector<string>& wordDict, vector<string>& words, vector<string>& result) {
        if(indx == s.length()) {
            string solution = "";
            for(string word : words) {
                solution += word;
                solution += ' ';
            }
            result.push_back(solution.substr(0, solution.length() - 1));
            return;
        }
        for(string word: wordDict) {
            int len = word.length();
            if(indx + len <= s.length() and s.substr(indx, len) == word) {
                words.push_back(word);
                wordBreak(indx + len, s, wordDict, words, result);
                words.pop_back();
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        if(!isPossible(s, wordDict)) {
            return result;
        }
        vector<string> words;
        wordBreak(0, s, wordDict, words, result);
        
        return result;
    }
};