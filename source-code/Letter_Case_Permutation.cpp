class Solution {
    void letterCasePermutation(int indx, string& S, vector<string>& result) {
        if(indx == S.length()) {
            result.push_back(S);
            return;
        }
        if(isalpha(S[indx])) {
            S[indx] = islower(S[indx]) ? toupper(S[indx]) : tolower(S[indx]);
            letterCasePermutation(indx + 1, S, result);
            S[indx] = islower(S[indx]) ? toupper(S[indx]) : tolower(S[indx]);
        }
        letterCasePermutation(indx + 1, S, result);
    }
    
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        letterCasePermutation(0, S, result);
        return result;
    }
};
