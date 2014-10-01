class Solution {
public:
    int singleNumber(int A[], int n) {
        map <int, int> freq; 
        for(int i = 0; i < n; ++i) ++freq[A[i]];
        for(int i = 0; i < n; ++i) if(freq[A[i]] < 2) return A[i];
    }
};