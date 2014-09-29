class Solution {
public:

    void combinationSumUtils(int indx, int sum, vector<int> &candidates, vector<int> &solution, vector<vector<int> > &result) {
        if(indx == candidates.size()) {
            if(sum == 0) result.push_back(solution);
            return;
        }
        if(sum == 0) {
            result.push_back(solution);
            return;
        }
        for(int i = indx; i < candidates.size(); ++i) {
            if(sum - candidates[i] >= 0) {
                solution.push_back(candidates[i]);
                combinationSumUtils(i, sum - candidates[i], candidates, solution, result);
                solution.pop_back();
            } else {
                break;
                // return;
            }
        }
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        vector<int> solution;
        if(candidates.size() < 0) return result;
        sort(candidates.begin(), candidates.end());
        combinationSumUtils(0, target, candidates, solution, result);
        return result;
    }
};