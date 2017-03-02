class Solution {
public:
    int singleNumber(int A[], int n) {
        map <int, int> freq;
        for(int i = 0; i < n; ++i) ++freq[A[i]];
        for(int i = 0; i < n; ++i) if(freq[A[i]] != 3) return A[i];
    }
	// best way: http://www.geeksforgeeks.org/find-the-element-that-appears-once/ 
};