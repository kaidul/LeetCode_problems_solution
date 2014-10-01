class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result;
        if(n == 0) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }

        // finding lower bound
        int mid, start = 0, end = n - 1;
        int x, y;
        while(start < end) {
            mid = start + (end - start) / 2;
            if(A[mid] < target) start = mid + 1;
            else if(A[mid] > target) end = mid - 1;
            else { // target == A[mid]
                if( (mid == 0) or (A[mid - 1] < A[mid]) ) {
                    x = mid; 
                    break; 
                }
                end = mid - 1;
            }
        }
        if(start >= end) x = A[start] == target ? start : -1;
        

        // finding upper bound
        start = 0, end = n - 1;
        while(start < end) {
            mid = start + (end - start) / 2;
            if(A[mid] < target) start = mid + 1;
            else if(A[mid] > target) end = mid - 1;
            else { // target == A[mid]
                if( (mid == n - 1) or (A[mid + 1] > A[mid]) ) {
                    y = mid; 
                    break; 
                }
                start = mid + 1;
            }
        }
        if(start >= end) y = A[start] == target ? start : -1;
        
        
        result.push_back(x);
        result.push_back(y);
        return result;
    }
};