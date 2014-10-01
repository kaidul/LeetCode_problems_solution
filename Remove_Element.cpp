class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int len = 0;
        for(int i = 0; i < n; ++i) {
            if (A[i] != elem) {
                A[len] = A[i];
                len++;
            }
        }
        return len;
    }
};