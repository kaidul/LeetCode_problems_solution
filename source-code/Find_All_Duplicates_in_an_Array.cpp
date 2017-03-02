class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i) {
            int indx = abs(nums[i]) - 1;
            if(nums[indx] < 0) {
                result.push_back(indx + 1);
            }
            nums[indx] = -nums[indx];
        }
        return result;
    }
};