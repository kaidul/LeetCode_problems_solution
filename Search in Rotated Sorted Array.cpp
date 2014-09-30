class Solution {
public:
    int search(int start, int end, int target, int A[]) {
        if (start > end) return -1;
        
        int mid = start + (end - start) / 2;
        if (A[mid] == target) return mid;
        
        if (A[mid] >= A[start]) {
            if (target <= A[mid] and target >= A[start]) {
                return search(start, mid - 1, target, A);
            } else {
                return search(mid + 1, end, target, A);
            }
        }
             
        if (A[mid] < A[start]) {
            if (target <= A[mid] or target >= A[start]) {
                return search(start, mid - 1, target, A);
            } else {
                return search(mid + 1, end, target, A);
            }
        }
        return -1;
    }

    int search(int A[], int n, int target) {
        // O(logn) Two pass needed (1) find pivot (2) search target
        /*
        int pivotIndx, mid, start = 0, end = n - 1;
        while(A[start] > A[end]) {
            mid = start + (end - start) / 2;
            if(A[mid] >= A[start]) start = mid + 1;
            else end = mid;
        }
        pivotIndx = start;
        
        if(pivotIndx > 0 and target >= A[0] and target <= A[pivotIndx - 1])
            start = 0, end = pivotIndx - 1;
        else if(target >= A[pivotIndx] and target <= A[n - 1])
            start = pivotIndx, end = n - 1;
        else return -1;
        
        while(start < end) {
            int mid = start + (end - start) / 2;
            if(target < A[mid]) end = mid - 1;
            else if (target > A[mid]) start = mid + 1;
            else return mid;
        }
        if(start == end) return A[start] == target ? start : -1;
        return -1;
        */

        // O(logn) one pass needed
        if(n == 0) return -1;
        return  search(0, n - 1, target, A);

    }
};