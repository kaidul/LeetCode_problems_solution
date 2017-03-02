class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = (int)nums.size();
        for(int i = 0; i < n - 1; i++) {
            nums.push_back(nums[i]);
        }
        stack<pair<int, int>> Stack;
        vector<int> result(n, -1);
        for(int i = 0; i < (int)nums.size(); ++i) {
            while(!Stack.empty() and Stack.top().first < nums[i]) {
                result[Stack.top().second] = nums[i];
                Stack.pop();
            }
            if(i < n) {
                Stack.push({nums[i], i});
            }
        }
        
        return result;
    }
};