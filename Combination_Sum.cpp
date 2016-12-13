class Solution {
public:

    void combinationSumUtils(int indx, int sum, vector<int> &candidates, vector<int> &solution, vector<vector<int> > &result) {
        if(sum == 0) {
            result.push_back(solution);
            return;
        }
        if(sum < 0) {
            return;
        }
        for(int i = indx; i < candidates.size(); ++i) {
            if(candidates[i] > sum) { break; }
            solution.push_back(candidates[i]);
            combinationSumUtils(i, sum - candidates[i], candidates, solution, result);
            solution.pop_back();
        }
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        vector<int> solution;
        if(candidates.empty()) return result;
        sort(candidates.begin(), candidates.end());
        combinationSumUtils(0, target, candidates, solution, result);
        return result;
    }
};