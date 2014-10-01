class Solution {
public:
	//  Explanation: http://yucoding.blogspot.com/2013/01/leetcode-question-50-median-of-two.html
    double findKth(int A[], int m, int B[], int n, int k) {

        if (m > n) return findKth(B, n, A, m, k);
        if (m == 0) return B[k - 1];
        if (k == 1) return min(A[0], B[0]);

        int aMid = min(k / 2, m);
        int bMid = k - aMid;

        if (A[aMid - 1] <= B[bMid - 1]) {
            return findKth(A + aMid, m - aMid, B, n, k - aMid);
        }
        return findKth(A, m, B + bMid, n - bMid, k - bMid);
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if(total & 1) return findKth(A, m, B, n, total / 2 + 1);
        return (findKth(A, m, B, n, total / 2) + findKth(A, m, B, n, total / 2 + 1)) / 2;
    }
};