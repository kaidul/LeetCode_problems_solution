class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int n = (int)findNums.size();
        int m = (int)nums.size();
        unordered_map<int, int> nxtGreaterMap;
        stack<int> Stack;
        for(int i = 0; i < m; i++) {
            while(!Stack.empty() and Stack.top() < nums[i]) {
                nxtGreaterMap[Stack.top()] = nums[i];
                Stack.pop();
            }
            Stack.push(nums[i]);
        }
        vector<int> result(n);
        for(int i = 0; i < n; i++) {
            result[i] = (nxtGreaterMap.count(findNums[i])) ? nxtGreaterMap[findNums[i]] : -1;
        }
        
        return result;
    }
};