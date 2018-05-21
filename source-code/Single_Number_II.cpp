class Solution {
public:
    int singleNumber(int A[], int n) {
        map <int, int> freq;
        for(int i = 0; i < n; ++i) ++freq[A[i]];
        for(int i = 0; i < n; ++i) if(freq[A[i]] != 3) return A[i];
    } 
};

// without extra space
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = (int) nums.size();
        int result = 0;
        for(int b = 0; b < 32; b++) { // sign bit matters here
            int bitSum = 0;
            for(int i = 0; i < n; i++) {
                bitSum += ((nums[i] & (1 << b)) != 0);
            }
            int bit = bitSum % 3;
            if(bit) {
                result |= (1 << b);
            }
        }
        return result;
    }
};
