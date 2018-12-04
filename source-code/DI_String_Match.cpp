class Solution {
public:
    vector<int> diStringMatch(string S) {
        int n = (int)S.length();
        int low = 0, high = n;
        vector<int> result;
        for (int i = 0; i < n; i++) {
            result.push_back(S[i] == 'D' ? high-- : low++);
        }
        assert(low == high);
        result.push_back(high); // or low
        
        return result;
    }
};