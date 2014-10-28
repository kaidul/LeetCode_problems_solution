class Solution {
public:
    bool isSkipped(int idx, int i, vector<int> &num) {
        for(int j = idx; j < i; ++j) {
            if(num[j] == num[i])
                return true;
        }
        return false;
    }
    void permuteUniqueUtils(int idx, vector<int> &num, vector<vector<int> > &result) {
        if(idx == num.size() - 1) {
            result.push_back(num);
            return;
        }
        for(int i = idx; i < num.size(); ++i) {
            if(isSkipped(idx, i, num)) continue;
            swap(num[idx], num[i]);
            permuteUniqueUtils(idx + 1, num, result);
            swap(num[idx], num[i]);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        if(num.size() == 0) return result;
        permuteUniqueUtils(0, num, result);
        return result;
    }
};