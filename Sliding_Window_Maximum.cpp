class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if(nums.size() < 1) return result;
        // O(n^2)
        /*
        int Max = INT_MIN;
        int indx = -1;
        for(int i = 0; i < k; ++i) {
            if(nums[i] >= Max) {
                Max = nums[i];
                indx = i;
            }
        }
        result.push_back(Max);
        for(int i = k; i < nums.size(); ++i) {
            if(nums[i] >= Max) {
                Max = nums[i];
                indx = i;
            } else if(indx == i - k) {
                Max = INT_MIN;
                for(int j = i - k + 1; j <= i; ++j) {
                    if(nums[j] >= Max) {
                        Max=  nums[j];
                        indx = j;
                    }
                }
            }
            result.push_back(Max);
        }
        */
        
        deque <int> Q(k);
        for(int i = 0; i < k; ++i) {
            while(!Q.empty() and nums[i] >= nums[Q.back()]) {
                Q.pop_back();
            }
            
            Q.push_back(i);
        }
        
        for(int i = k; i < nums.size(); ++i) {
            result.push_back(nums[Q.front()]);
            
            while(!Q.empty() and Q.front() <= i - k) {
                Q.pop_front();
            }
            while(!Q.empty() and nums[i] >= nums[Q.back()]) {
                Q.pop_back();
            }
            
            Q.push_back(i);
        }
        
        result.push_back(nums[Q.front()]);
        // #################################
        return result;
    }
};