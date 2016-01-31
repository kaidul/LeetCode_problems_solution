class Solution {
public:
    int hIndex(vector<int>& citations) {
        int hIndx = 0;
        int n = citations.size();
        for(int i = n - 1; i >= 0; --i) {
            if(citations[i] < n - i) break;
            hIndx = max(hIndx, n - i);
        }
        return hIndx;
    }
};