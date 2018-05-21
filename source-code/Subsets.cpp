class Solution {
public:
    void subsetsUtils(int idx, vector<int> &S, vector<int> &solution, vector<vector<int> > &result) {
        result.push_back(solution);
        if(idx == S.size()) {
            return;
        }

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
        subsetsUtils(0, S, solution, result);
        return result;
    }
};

// Alternatives

class Solution {
public:
    void subsetsUtils(int idx, vector<int> &S, vector<int> &solution, vector<vector<int> > &result) {
        if(idx == S.size()) {
            result.push_back(solution);
            return;
        }
        solution.push_back(S[idx]);
        subsetsUtils(idx + 1, S, solution, result);
        solution.pop_back();
        subsetsUtils(idx + 1, S, solution, result);
    }
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > result;
        vector<int> solution;
        if(S.size() < 0) return result;
        subsetsUtils(0, S, solution, result);
        return result;
    }
};
