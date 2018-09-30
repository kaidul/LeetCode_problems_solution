class Solution {
public:
    vector<int> searchRange(vector<int>& A, int target) {
        vector<int> result;
        int n = A.size();
        if(n == 0) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }

        // finding lower bound
        int mid, start = 0, end = n - 1;
        int x = -1, y = -1;
        while(start <= end) {
            mid = start + (end - start) / 2;
            if(A[mid] < target) {
                start = mid + 1;  
            } else if(A[mid] >= target) {
                if(A[mid] == target) {
                    x = mid;
                }
                end = mid - 1;
            }
        }
        

        // finding upper bound
        start = 0, end = n - 1;
        while(start <= end) {
            mid = start + (end - start) / 2;
            if(A[mid] < target) start = mid + 1;
            else if(A[mid] > target) {
                end = mid - 1;
            } else if(A[mid] <= target) {
                if(A[mid] == target) {
                    y = mid;
                }
                start = mid + 1;
            }
        }
        
        
        result.push_back(x);
        result.push_back(y);
        return result;
    }
};