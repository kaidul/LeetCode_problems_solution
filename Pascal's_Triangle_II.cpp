class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector <int> prev, result;
        result.push_back(1);
        if(rowIndex == 0) return result;
        
        result.push_back(1);
        if(rowIndex == 1) return result;
        
        prev = result;
        for(int i = 2; i <= rowIndex; ++i) {
            result.clear();
            result.push_back(1);
            for(int j = 0, n = prev.size(); j < n - 1; ++j) {
                result.push_back(prev[j] + prev[j + 1]);
            }
            result.push_back(1);
            prev = result;
        }
        return result;
    }
};