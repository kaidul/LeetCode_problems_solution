class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        if(k == 0 or nums.empty()) return result;
        result.resize(k);
        int n = (int)nums.size();
        unordered_map<int, int> freq;
        // O(n)
        for(int i = 0; i < n; ++i) {
            if(freq.find(nums[i]) == freq.end()) {
                freq[nums[i]] = 0;
            }
            freq[nums[i]]++;
        }
        // O(nlogk)
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;
        for(auto it = freq.begin(); it != freq.end(); ++it) {
            if(Q.size() < k) {
                Q.push({it->second, it->first});    
            } else {
                if(it->second > Q.top().first) {
                    Q.pop();
                    Q.push({it->second, it->first});
                }
            }
        }
        // O(klogk)
        int i = k - 1;
        while(!Q.empty()) {
            result[i--] = Q.top().second;
            Q.pop();
        }
        
        return result;
    }
};