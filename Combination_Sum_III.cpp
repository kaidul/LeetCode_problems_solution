class Solution {
public:
    void combinationSum3Util(int item, int k, int sum, vector<int>& solution, vector<vector<int>> &result) {
        if(solution.size() == k) {
            if(sum == 0) {
                result.push_back(solution);
            }
            return;
        }
        if(item > 9 or item > sum) return;
        solution.push_back(item);
        combinationSum3Util(item + 1, k, sum - item, solution, result);
        solution.pop_back();
        combinationSum3Util(item + 1, k, sum, solution, result);
    }

    void combinationSum3Util2(int item, int k, int sum, vector<int>& solution, vector<vector<int>> &result) {
        if(solution.size() == k) {
            if(sum == 0) {
                result.push_back(solution);
            }
            return;
        }
        for(int val = item; val <= 9; val++) {
            if(val <= sum) {
                solution.push_back(val);
                combinationSum3Util2(val + 1, k, sum - val, solution, result);
                solution.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> solution;
        combinationSum3Util(1, k, n, solution, result);
        return result;
    }
};