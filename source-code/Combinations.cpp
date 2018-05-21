class Solution {
public:
    void combineUtils(int idx, int n, int k, vector<int> &solution, vector<vector<int> > &result) {
        if(solution.size() == k) {
            result.push_back(solution);
            return;
        }
        for(int i = idx; i <= n; ++i) {
            solution.push_back(i);
            combineUtils(i + 1, n, k, solution, result);
            solution.pop_back();
        }
    }

    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> solution;
        if(k == 0 or n == 0) return result;
        combineUtils(1, n, k, solution, result);
        return result;
    }
};

// Alternatives
class Solution {
public:
    void combineUtils(int idx, int n, int k, vector<int> &solution, vector<vector<int> > &result) {
        if(idx > n or solution.size() == k) {
            if(solution.size() == k)
                result.push_back(solution);
            return;
        }
        if(solution.size() < k) {
            solution.push_back(idx);
            combineUtils(idx + 1, n, k, solution, result);
            solution.pop_back();    
        }
        
        combineUtils(idx + 1, n, k, solution, result);
    }

    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> solution;
        if(k == 0 or n == 0) return result;
        combineUtils(1, n, k, solution, result);
        return result;
    }
};
