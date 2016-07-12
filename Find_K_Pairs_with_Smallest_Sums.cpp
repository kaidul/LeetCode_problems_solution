class Solution {
    
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue <pair<long long, pair<int, int>>> maxHeap;
        for(int i = 0; i < (int)nums1.size(); ++i) {
            for(int j = 0; j < (int)nums2.size(); ++j) {
                if((int)maxHeap.size() == k and nums1[i] + nums2[j] >= maxHeap.top().first) {
                    break;
                }
                if((int)maxHeap.size() < k) {
                    maxHeap.push({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
                } else {
                    if(maxHeap.top().first > nums1[i] + nums2[j]) {
                        maxHeap.pop();
                        maxHeap.push({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
                    }
                }
            }
        }
        vector<pair<int, int>> result;
        result.resize((int)maxHeap.size());
        while(!maxHeap.empty()) {
            result[(int)maxHeap.size() - 1] = maxHeap.top().second;
            maxHeap.pop();
        }
        
        return result;
    }
};