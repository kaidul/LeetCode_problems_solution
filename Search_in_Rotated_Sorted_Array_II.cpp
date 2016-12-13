class Solution {
    bool search(int start, int end, int target, vector<int>& A) {
        if (start > end) return false;
        
        int mid = start + (end - start) / 2;
        if (A[mid] == target) return true;
        
        if(A[start] == A[mid] and A[mid] == A[end]) {
            return search(mid + 1, end, target, A) | search(start, mid - 1, target, A);
        }
        
        if (A[mid] >= A[start]) {
            if (target < A[mid] and target >= A[start]) {
                return search(start, mid - 1, target, A);
            } else {
                return search(mid + 1, end, target, A);
            }
        }
             
        if (A[mid] < A[start]) {
            if (target < A[mid] or target >= A[start]) {
                return search(start, mid - 1, target, A);
            } else {
                return search(mid + 1, end, target, A);
            }
        }
        
        return false;
    }
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        return  search(0, (int)nums.size() - 1, target, nums);
    }
};