class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int result = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0, n = nums.size(); i < n - 2; ++i) {
            int left = i + 1, right = n - 1;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum >= target) {
                    right--;
                } else {
                    result += (right - left);
                    left++;
                }
            }
        }
        return result;
    }
};