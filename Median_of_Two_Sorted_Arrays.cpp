class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        if(((int)nums1.size() - i) > ((int)nums2.size() - j))
            return findMedianSortedArrays(nums2, j, nums1, i, k);
        if(i >= (int) nums1.size()) return nums2[j + k - 1];
        if(k == 1) return min(nums1[i], nums2[j]);
        int aMid = min(k / 2, (int)nums1.size() - i);
        int bMid = k - aMid;
        if(nums1[i + aMid - 1] <= nums2[j + bMid - 1])
            return findMedianSortedArrays(nums1, i + aMid, nums2, j, k - aMid);
        return findMedianSortedArrays(nums1, i, nums2, j + bMid, k - bMid);
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if(total & 1) return findMedianSortedArrays(nums1, 0, nums2, 0, total / 2 + 1);
        return (findMedianSortedArrays(nums1, 0, nums2, 0, total / 2) + findMedianSortedArrays(nums1, 0, nums2, 0, total / 2 + 1)) / 2;
    }
};