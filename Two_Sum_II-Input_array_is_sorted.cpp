class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int n = numbers.size();
        if(n == 0) return result;
        int left = 0, right = n - 1;
        while(left < right) {
            int sum = numbers[left] + numbers[right];
            if(sum > target) {
                --right;
            } else if(sum < target) {
                ++left;
            } else {
                result.push_back(left + 1);
                result.push_back(right + 1);
                break;
            }
        }
        return result;
    }
};