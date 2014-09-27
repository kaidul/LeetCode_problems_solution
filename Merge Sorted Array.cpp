class Solution {
public:
    // AC but Extra space : O(m)
    /*
    void merge(int A[], int m, int B[], int n) {
        int tmp[m];
        memcpy(tmp, A, m * sizeof(int));
        int k = 0, i = 0, j = 0;
        while(i < m and j < n) {
            if(tmp[i] <= B[j]) A[k++] = tmp[i++];
            else A[k++] = B[j++];
        }
        while(i < m) {
            A[k++] = tmp[i++];
        }
        while(j < n) {
            A[k++] = B[j++];
        }
    }
    */
    
    void merge(int A[], int m, int B[], int n) {
        int count = m + n - 1;
        m--; n--;
        while (m >= 0 and n >= 0) {
            A[count--] = A[m] > B[n] ? A[m--] : B[n--];
        }
        while (n >= 0) { A[count--] = B[n--]; }
    }
};