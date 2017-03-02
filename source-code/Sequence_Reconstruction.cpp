class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if(seqs.empty()) return false;
        int n = org.size();
        vector<bool> pair(n, false);
        vector<int> indx(n + 1);
        for(int i = 0 ; i < n; ++i) {
            indx[org[i]] = i;
        }
        bool isEmpty = true;
        for(int i = 0; i < seqs.size(); ++i) {
            for(int j= 0; j < seqs[i].size(); ++j) {
                isEmpty = false; 
                if(seqs[i][j] > n or seqs[i][j] <= 0) {
                    return false;
                }
                if(j > 0 and indx[seqs[i][j - 1]] >= indx[seqs[i][j]]) {
                    return false;
                }
                if(j > 0 and indx[seqs[i][j - 1]] + 1 == indx[seqs[i][j]]) {
                    pair[indx[seqs[i][j - 1]]] = true;
                }
            }
        }
        for(int i = 0 ; i < n - 1; ++i) {
            if(!pair[i]) {
                return false;
            }
        }
        if(n == 1 and isEmpty) return false;
        return true;
    }
};