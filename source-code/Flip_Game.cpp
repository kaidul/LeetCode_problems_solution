class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> result;
        for(int i = 0, n = s.length(); i < n - 1; ++i) {
            if(s[i] == '+' and s[i + 1] == '+') {
                s[i] = s[i + 1] = '-';
                result.push_back(s);
                s[i] = s[i + 1] = '+';
            }
        }
        return result;
    }
};