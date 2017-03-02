class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0 or n == 1) return n;
        int len = n;
        int prev = 0;
        for(int i = 1; i < n; ++i) {
            if(A[prev] == A[i]) {
                --len;
            } else {
                A[prev + 1] = A[i];
                ++prev;
            }
        }
        return len;
    }
};