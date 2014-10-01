class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(n == 0) return 0;
        int start = 0, end = n - 1, mid;
        while(start < end) {
            mid = start + (end - start) / 2;
            if(target < A[mid]) end = mid - 1;
            else if(target > A[mid]) start = mid + 1;
            else break;
        }
        if(start >= end) {
            if(A[start] < target) return start + 1;
            else return start;
        }
        return mid;
    }
};