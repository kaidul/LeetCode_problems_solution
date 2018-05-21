class Solution {
public:
    // AC but Extra space : O(m)
    /*
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        vector<int> tmp(A);
        int k = 0, i = 0, j = 0;
        while(i < m and j < n) {
            if(tmp[i] <= B[j]) 
	    	A[k++] = tmp[i++];
            else
	    	A[k++] = B[j++];
        }
        while(i < m) {
            A[k++] = tmp[i++];
        }
        while(j < n) {
            A[k++] = B[j++];
        }
    }
    */

	
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1;
        m--; n--;
        while(m >= 0 and n >= 0) {
            nums1[k--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--]; 
        }
        while(n >= 0) {
            nums1[k--] = nums2[n--];
        }
    }
};
