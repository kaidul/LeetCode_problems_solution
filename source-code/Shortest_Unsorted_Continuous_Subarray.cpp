class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> numsSorted(nums);
        sort(numsSorted.begin(), numsSorted.end());
        int n = nums.size();
        int left = 0, right = n - 1;
        while(left < n and nums[left] == numsSorted[left]) {
            left++;
        }
        while(right >= left and nums[right] == numsSorted[right]) {
            right--;
        }
        return max(0, right - left + 1);
    }
};