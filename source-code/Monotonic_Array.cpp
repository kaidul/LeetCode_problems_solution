class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool isDecreasing = true;
        for(int i = 0; i < A.size() - 1; i++) {
            if(A[i] < A[i + 1]) {
                isDecreasing = false;
                break;
            }
        }
        if(isDecreasing)
            return true;
        
        bool isIncreasing = true;
        for(int i = 0; i < A.size() - 1; i++) {
            if(A[i] > A[i + 1]) {
                isIncreasing = false;
                break;
            }
        }
        if(isIncreasing)
            return true;
        
        return false;
        
    }
};