class Solution {
public:
    // the commented lines are for finding maximum elements
    int findMin(int left, int right, vector<int> &num) {
        if(left > right) return INT_MAX;
        if(left == right) return num[left];
        int mid = left + (right - left) / 2;
        if(num[left] > num[right]) {
            if(num[mid] >= num[left]) {
                return findMin(mid + 1, right, num);
                // return max(findMax(mid, right, num), findMax(left, mid - 1, num)); 
            } else {
                return min(findMin(mid, right, num), findMin(left, mid - 1, num));
                // return findMax(left, mid - 1, num);
            }
        } else {
             return num[left];
             // return num[right];
        }
    }
    int findMin(vector<int> &num) {
        return findMin(0, num.size() - 1, num);
        
    }
};