class Solution {
public:
    // O(n) because fadup to find an O(logn) solution 
    bool search(int A[], int n, int target) {
         for(int i = 0; i < n; ++i) {
             if(A[i] == target)
                return true;
         }
         return false;
    }
};