class Solution {
public:
    // time: O(n), space: O(k)
    /*
    void rotate(int nums[], int n, int k) {
        if(k > n) k %= n;
        if(k < 1 or n < 2) return;
        int tmp[k];
        for(int i =  n - k; i < n; ++i) {
            tmp[i - n + k] = nums[i];
        }
        for(int i = n - k - 1; i >= 0; --i) {
            nums[i + k] = nums[i];
        }
        for(int i = 0; i < k; ++i) {
            nums[i] = tmp[i];
        }
    }
    */

    // reversal algorithm; time: O(n), no extra space
    void rotate(int nums[], int n, int k) {
        if(k > n) k %= n;
        if(k < 1 or n < 2) return;
        for(int i = 0, j = n - k - 1; i < j; ++i, --j) {
            nums[i] = nums[i] ^ nums[j];
            nums[j] = nums[i] ^ nums[j];
            nums[i] = nums[i] ^ nums[j];
        }
        for(int i = n - k, j = n - 1; i < j; ++i, --j) {
            nums[i] = nums[i] ^ nums[j];
            nums[j] = nums[i] ^ nums[j];
            nums[i] = nums[i] ^ nums[j];
        }
        for(int i = 0, j = n - 1; i < j; ++i, --j) {
            nums[i] = nums[i] ^ nums[j];
            nums[j] = nums[i] ^ nums[j];
            nums[i] = nums[i] ^ nums[j];
        }
    }
};