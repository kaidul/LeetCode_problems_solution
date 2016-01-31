class Solution {
public:
    int singleNumber(int A[], int n) {
    	// A XOR A = 0, and A XOR B XOR A = B
        int res = A[0];
        for (int i = 1; i < n; i++) {
            res = res ^ A[i];
        }
        return res;
        
        /*
        sort(A, A + n);
        for(int i = 0; i < n - 1; i += 2) {
            if(A[i] != A[i + 1]) return A[i];
        }
        return A[n - 1];
        */
        
        // extra space
        /*
        map <int, int> freq; 
        for(int i = 0; i < n; ++i) ++freq[A[i]];
        for(int i = 0; i < n; ++i) if(freq[A[i]] < 2) return A[i];
        */
    }
};