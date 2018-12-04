class Solution {
    void findGroup(int left, int right, vector<vector<int>>& result) {
        int len = right - left;
        if (len >= 3) {
            vector<int> group {left, right - 1};
            result.push_back(group);
        }
    }
    
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> result;
        int left = 0, right = 0;
        while (right < (int)S.length()) {
            if (S[left] != S[right]) {
                findGroup(left, right, result);
                left = right;
            }
            right++;
        }
        findGroup(left, right, result);
        
        return result;
    }
};