class Solution {
    bool isSummit(vector<int>& A, int indx) {
        if(indx > 0 and 
           indx < A.size() - 1 and 
           A[indx] > A[indx - 1] and 
           A[indx] > A[indx + 1]) {
            return true;
        }
        return false;
    }
public:
    int peakIndexInMountainArray(vector<int>& A) {
        for(int i = 0; i < A.size(); i++) {
            if(isSummit(A, i)) {
                return i;
            }
        }
        return INT_MIN;
    }
};