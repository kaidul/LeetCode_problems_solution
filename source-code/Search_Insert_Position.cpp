class Solution {
public:
    int searchInsert(vector<int>& A, int target) {
        int n = (int)A.size();
        if(n == 0) return 0;
        int start = 0, end = n - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(target == A[mid]) {
                return mid;
            }
            if(target > A[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return start;
    }
};