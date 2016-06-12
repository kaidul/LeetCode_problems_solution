class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.empty()) return;
        int n = nums.size();
        int flag = 1;
        for(int i = 0; i < n - 1; ++i) {
            if(flag) {
                if(nums[i] > nums[i + 1]) {
                    swap(nums[i], nums[i + 1]);
                }
                flag ^= 1;
            } else {
                if(nums[i] < nums[i + 1]) {
                    swap(nums[i], nums[i + 1]);
                }
                flag ^= 1;
            }
        }
    }
};
// with extra space\
/*
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return;
        sort(nums.begin(), nums.end());
        int mid = n / 2;
        if(n & 1) mid++;
        int tmp[n - mid];
        for(int k = 0, i = mid; i < n; ++i, ++k) {
            tmp[k] = nums[i];
        }
        for(int i = mid - 1; i > 0; --i) {
            nums[i << 1] = nums[i];
        }
        for(int i = 1, k = 0; i < n; i += 2, ++k) {
            nums[i] = tmp[k];
        }
    }
};
*/