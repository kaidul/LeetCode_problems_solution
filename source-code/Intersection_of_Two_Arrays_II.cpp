class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        if(n > m) return intersect(nums2, nums1);
        unordered_map<int, int> freq1, freq2;
        for(int i = 0; i < n; ++i) {
            freq2[nums2[i]]++;
        }
        for(int i = 0; i < m; ++i) {
            freq1[nums1[i]]++;
        }
        vector<int>result;
        for(auto it = freq2.begin(); it != freq2.end(); ++it) {
            int key = it->first;
            int occur2 = it->second;
            if(freq1.find(key) != freq1.end()) {
                int occur1 = freq1.find(key)->second; 
                for(int k = 0; k < min(occur1, occur2); ++k) {
                    result.push_back(key);
                }
            }
        }
        
        return result;
    }
};