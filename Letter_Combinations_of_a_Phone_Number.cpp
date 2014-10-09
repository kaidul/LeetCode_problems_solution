class Solution {
public:

    void dfs(string digits, string r, map<char, vector<char> > &mp, vector<string> &res) {
        if ( digits.empty() ) {
            res.push_back(r);
            return;
        }
        vector<char> vec = mp[digits[0]];
        for(int i = 0; i < vec.size(); i++) {
            dfs(digits.substr(1), r + vec[i], mp, res);
        }
    }

    vector<string> letterCombinations(string digits) {
        map<char, vector<char> > mp;
        vector<char> v;
        int n = 2;
        for (char i = 'a'; i <= 'z'; i++) {
            v.push_back(i);
            if (i == 'c' || i == 'f'|| i == 'i'|| i == 'l'|| i == 'o'|| i == 's'|| i == 'v'|| i == 'z') {
                mp[ char(n + '0') ] = v;
                n++;
                v.clear();
            }
        }

        vector<string> res;
        dfs(digits, "", mp, res);
        return res;
    }

};