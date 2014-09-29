class Solution {
public:
    void subsetsUtils(int idx, vector<int> &S, vector<int> &solution, vector<vector<int> > &result) {
        if(idx == S.size()) {
            result.push_back(solution);
            return;
        }
        result.push_back(solution);

        int prev = numeric_limits<int>::max();
        for(int i = idx; i < S.size(); ++i) {
            if(S[i] != prev) {
                solution.push_back(S[i]);
                subsetsUtils(i + 1, S, solution, result);
                solution.pop_back();
                prev = S[i];
            }
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