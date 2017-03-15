class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> wordSet(words.begin(), words.end());
        vector<string> result;
        int n = (int)words.size();
        for(int i = 0; i < n; i++) {
            int m = (int)words[i].length();
            vector<bool> dp(m + 1, false);
            dp[0] = true;
            for(int j = 0; j < m; j++) {
                if(dp[j]) {
                    for(int len = 1; len <= min(m - j, m - 1); len++) {
                        if(wordSet.count(words[i].substr(j, len))) {
                            dp[j + len] = true;     
                        }
                    }
                    if(dp[m]) {
                        result.push_back(words[i]);
                        break;
                    }
                    
                }
            }
        }
        return result;
    }
};