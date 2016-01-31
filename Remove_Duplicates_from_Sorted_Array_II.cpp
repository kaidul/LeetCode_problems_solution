class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n < 3) return n;
        int prev = 0, len = n;
        bool flag = false;
        for(int i = 1; i < n; ++i) {
            if(A[prev] == A[i]) {
                if(!flag) {
                    ++prev;
                    A[prev] = A[i];
                    flag = true;
                } else {
                    --len;
                }
            } else {
                A[prev + 1] = A[i];
                prev++;
                flag = false;
            }
        }
        return len;
    }
};