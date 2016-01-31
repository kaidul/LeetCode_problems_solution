class Solution {
public:

    void wordBreakUtils(string s, unordered_set<string> &dict, string solution, vector<string> &result) {
        if(s.length() == 0) {
            solution.erase(solution.length() - 1, 1);
            result.push_back(solution);
            return;
        }
        for(auto it = dict.begin(); it != dict.end(); ++it) {
            int len = (*it).length();
            if(len > s.length()) continue;
            if(s.substr(0, len) == *it) {
                wordBreakUtils(s.substr(len, s.length() - len), dict, solution + (*it) + " ", result);
            }
        }
    }

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // make sure with dp whether there is any solution to avoid TLE
        // causing by unnecessary search when there is no solution
        vector<vector<bool> > dp(s.length(), vector<bool>(s.length(), false));
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                if (dict.find(s.substr(i, j - i + 1)) != dict.end()) {
                    dp[i][j] = true;
                }
            }
        }

        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                for(int k = i; k <= j; ++k) {
                    if(!dp[i][j]) dp[i][j] = dp[i][k] and dp[k + 1][j];
                }
            }
        }

        vector<string> result;
        string solution;
        if(!dp[0][s.length() - 1]) return result;
        // only DFS would yield TLE (without prior checking)
        wordBreakUtils(s, dict, solution, result);
        return result;
    }
};