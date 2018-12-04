class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = (int)A.size();
        if(n < 3 or A[0] > A[1]) {
            return false;
        }
        bool isAscending = true;
        int peakIndx = 0;
        for (int i = 1; i < n; i++) {
            if (A[i] == A[i - 1]) {
                return false;
            }
            if (A[i] > A[peakIndx] and isAscending) {
                peakIndx = i;
                continue;
            } else {
                isAscending = false;
            }
            
            if (!isAscending and A[i] > A[i - 1]) {
                return false;
            }
        }
        
        return !isAscending and peakIndx > 0 and peakIndx < n - 1;
    }
};