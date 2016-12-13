class Solution {
    void lexicalOrderUtil(int curr, int n, vector<int>& result) {
        if(curr > n) {
            return;
        }
        result.push_back(curr);
        for(int x = 0; x <= 9; ++x) {
            lexicalOrderUtil(curr * 10 + x, n, result);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for(int x = 1; x <= 9; ++x) {
            lexicalOrderUtil(x, n, result);
        }
        return result;
    }
};