class Solution {
public:
    void subsetsUtils(int idx, vector<int> &S, vector<int> &solution, vector<vector<int> > &result) {
        if(idx == S.size()) {
            result.push_back(solution);
            return;
        }
        result.push_back(solution);

        for(int i = idx; i < S.size(); ++i) {
            solution.push_back(S[i]);
            subsetsUtils(i + 1, S, solution, result);
            solution.pop_back();
        }
    }
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > result;
        vector<int> solution;
        if(S.size() < 0) return result;
        sort(S.begin(), S.end());
        subsetsUtils(0, S, solution, result);
        return result;
    }
};