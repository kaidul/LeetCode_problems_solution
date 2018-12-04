class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        int n = (int) A.size();
        vector<int> result(n);
        unordered_map<int, vector<int>> index;
        for (int i = 0; i < n; i++) {
            index[A[i]].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            int indx = index[B[i]].back();
            result[indx] = i;
            index[B[i]].pop_back();
        }
        
        return result;
    }
};