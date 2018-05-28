class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int hIndx = 0;
        for(int i = 0; i < citations.size(); ++i) {
            if(citations[i] < i + 1) break;
            hIndx = i + 1;
        }
        return hIndx;
    }
};
