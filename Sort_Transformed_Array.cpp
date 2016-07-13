// O(n) using parabola curve nature
class Solution {
    inline int getValue(int x, int a, int b, int c) {
        return (a * x * x + b * x + c);
    }
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = (int) nums.size();
        vector<int> result;
        if(n == 0) return result;
        result.resize(n);
        int left = 0, right = n - 1;
        int indx = (a > 0) ? n - 1 : 0;
        while(left <= right) {
            int leftVal = getValue(nums[left], a, b, c);
            int rightVal = getValue(nums[right], a, b, c);
            if(a > 0) {
                if(leftVal >= rightVal) {
                    result[indx--] = leftVal;
                    left++;
                } else {
                    result[indx--] = rightVal;
                    right--;
                }
            } else {
                if(leftVal <= rightVal) {
                    result[indx++] = leftVal;
                    ++left;
                } else {
                    result[indx++] = rightVal;
                    --right;
                }
            }
        }
        
        return result;
    }
};

// brute force
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = (int) nums.size();
        vector<int> result;
        if(n == 0) return result;
        result.resize(n);
        for(int i = 0; i < n; ++i) {
            result[i] = a * (nums[i] * nums[i]) + b * nums[i] + c;
        }
        sort(result.begin(), result.end());
        
        return result;
    }
};