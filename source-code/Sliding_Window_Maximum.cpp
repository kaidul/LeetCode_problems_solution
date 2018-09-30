class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         vector<int> result;
        if(nums.size() < 1) return result;
        
        unordered_map<int, int> freq;
        set<int> numSet;
        for(int i = 0; i < k; i++) {
            freq[nums[i]]++;
            numSet.insert(nums[i]);
        }
        auto max = --numSet.end();
        result.push_back(*max);
        for(int i = k; i < nums.size(); i++) {
            freq[nums[i]]++;
            numSet.insert(nums[i]);
            
            freq[nums[i - k]]--;
            if(freq[nums[i - k]] == 0) {
                numSet.erase(nums[i - k]);
            }
            
            auto max = --numSet.end();
            result.push_back(*max);
        }
        
        return result;
    }
};

// using deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if(nums.size() < 1) return result;
        
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

        return result;
    }
};