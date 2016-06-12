class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        if(n > m) return intersection(nums2, nums1);
        if(n == 0) return nums2;
        unordered_set<int> common;
        for(int i = 0; i < n; ++i) {
            common.insert(nums2[i]);
        }
        unordered_set<int> resultSet;
        for(int i = 0; i < m; ++i) {
            if(common.find(nums1[i]) != common.end()) {
                resultSet.insert(nums1[i]);
            }
        }
        
        vector<int> result(resultSet.begin(), resultSet.end());
        
        return result;
    }
};