class Solution {
    void getFactorsImpl(int n, vector<int>& solution, vector<vector<int>>& result) {
        if(!solution.empty()) {
            solution.push_back(n);
            result.push_back(solution);
            solution.pop_back();
        }
        for(int i = solution.empty() ? 2 : max(2, solution[solution.size() - 1]); i <= (int)floor(sqrt(n)); ++i) {
            if(n % i == 0) {
                int factor = n / i;
                if(factor < i) break;
                solution.push_back(i);
                getFactorsImpl(factor, solution, result);
                solution.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> solution;
        vector<vector<int>> result;
        getFactorsImpl(n, solution, result);
        return  result;
    }
};