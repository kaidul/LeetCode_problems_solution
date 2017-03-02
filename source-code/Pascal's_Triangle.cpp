class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector <vector<int> > result;
        if(numRows == 0) return result;
        
        vector<int> container;
        container.push_back(1);
        result.push_back(container);
        if(numRows == 1) return result;
        
        container.push_back(1);
        result.push_back(container);
        if(numRows == 2) return result;
        
        vector<int> vec;
        for(int i = 2; i < numRows; ++i) {
            vec.push_back(1);
            for(int j = 0, n = result[i - 1].size(); j < n - 1; ++j) {
                vec.push_back(result[i - 1][j] + result[i - 1][j + 1]);
            }
            vec.push_back(1);
            result.push_back(vec);
            vec.clear();
        }
        
        return result;
    }
};