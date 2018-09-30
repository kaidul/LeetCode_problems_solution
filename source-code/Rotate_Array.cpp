class Solution {
public:

    // reversal algorithm; time: O(n)
    void swapRange(vector<int>& nums, int left, int right) {
        --right;
        while(left < right) {
            swap(nums[left], nums[right]);
            left++, right--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        swapRange(nums, 0, n - k);
        swapRange(nums, n - k, n);
        swapRange(nums, 0, n);
    }
};


// shifting
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = (int) nums.size();
        k %= n;
        int count = 0;
        for(int start = 0; count < n; start++) {
            int currIndx = start;
            int tmp = nums[currIndx];
            do {
                int nextIndx = (currIndx + k) % n;
                swap(tmp, nums[nextIndx]);
                currIndx = nextIndx;
                count++;
            } while(currIndx != start);
        }
    }
};