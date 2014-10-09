class Solution {
public:
    int maxArea(vector<int> &height) {
        /* O(n^2) TLE
        if(height.size() < 0) return 0;
        int Max = numeric_limits<int>::min();
        for(int i = 0; i < height.size() - 1; ++i) {
            for(int j = i + 1; j < height.size(); ++j) {
                Max = max(Max, (j - i)*min(height[i], height[j]));
            }
        }
        return Max;
        */
        if(height.size() < 2) return 0;
        int Max = numeric_limits<int>::min();
        int left = 0;
        int right = height.size() - 1;
         
        while(left < right) {
            int value = (right - left) * min(height[left], height[right]);
            Max = max(Max, value);
            
            if(height[left] < height[right]) left++;
            else right--;
        }
        return Max;
    }
};