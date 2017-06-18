class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = (int)nums.size();
        if(n <= 2) return 0;
        int count = 0;
        sort(nums.begin(), nums.end());
        int offset = 0;
        while(offset < n and nums[offset] == 0) { offset++; }
        for(int i = n - 1; i >= offset + 2; i--) {
            int a = nums[i];
            for(int j = i - 1; j >= offset + 1; j--) {
                int b = nums[j];
                int left = offset, right = j - 1;
                int cIndx = -1;
                while(left <= right) {
                    int mid = left + (right - left) / 2;
                    if(nums[mid] + b > a) {
                        cIndx = mid;
                        right = mid - 1;
                    } else if(nums[mid] + b <= a) {
                        left = mid + 1;
                    }
                }
                if(cIndx != -1) {
                    count += (j - cIndx);
                }
            }
        }
        return count;
    }
};