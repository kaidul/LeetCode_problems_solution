class Solution {
public:
    int maxProduct(int A[], int n) {
        int res = A[0];
        int pos = max(0, A[0]);
        int neg = min(0, A[0]);
        for (int i = 1; i < n; ++i) {
            if (A[i] == 0) {
                pos = 0;
                neg = 0;
            } else if (A[i] > 0) {
                pos = max(A[i], pos * A[i]);
                neg *= A[i];
            } else {
                int tmp = pos;
                pos = neg * A[i];
                neg = min(A[i], A[i] * tmp);
            }
            res = max(res, pos);
        }
        return res;
    }
};