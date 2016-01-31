class Solution {
public:
    void combinationSum2Utils(int indx, int sum, vector<int> &candidates, vector<int> &solution, vector<vector<int> > &result) {
        if(indx == candidates.size()) {
            if(sum == 0) result.push_back(solution);
            return;
        }
        if(sum == 0) {
            result.push_back(solution);
            return;
        }
        int prev = -1;
        for(int i = indx; i < candidates.size(); ++i) {
            if(sum - candidates[i] >= 0) {
                if(prev == candidates[i]) continue;
                solution.push_back(candidates[i]);
                combinationSum2Utils(i + 1, sum - candidates[i], candidates, solution, result);
                solution.pop_back();
                prev = candidates[i];
            } else {
                break;
                // return;
            }
        }
    }

    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        vector<int> solution;
        if(candidates.size() < 0) return result;
        sort(candidates.begin(), candidates.end());
        combinationSum2Utils(0, target, candidates, solution, result);
        return result;
    }
};