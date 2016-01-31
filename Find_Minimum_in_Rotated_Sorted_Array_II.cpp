class Solution {
public:
    int findMin(int left, int right, vector<int> &num) {
        if(left > right) return INT_MAX;
        if(left == right) return num[left];
        if(num[left] < num[right]) return num[left];
        
        int mid = left + (right - left) / 2;
        if(num[left] == num[mid] and num[mid] == num[right]) {
            return min(findMin(left, mid, num), findMin(mid + 1, right, num));
        }
        if(num[mid] > num[right]) {
            return findMin(mid + 1, right, num);
        } else {
            return findMin(left, mid, num);
        }
    }
    int findMin(vector<int> &num) {
        return findMin(0, num.size() - 1, num);
    }
};