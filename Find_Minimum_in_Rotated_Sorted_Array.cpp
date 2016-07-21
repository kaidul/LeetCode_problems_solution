class Solution {
public:
    int findMin(int left, int right, vector<int> &num) {
        // if(left > right) return INT_MAX;
        if(left == right) return num[left];
        if(num[left] < num[right]) return num[left];
        
        int mid = left + (right - left) / 2;
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

// iterative
int Solution::findMin(const vector<int> &arr) {
    int n = arr.size();
    int left = 0, right = n - 1;
    while(left <= right) {
        if(arr[left] <= arr[right]) return arr[left];
        int mid = left + (right - left) / 2;
        if(arr[mid] > arr[right]) {
            left = mid + 1;
        } else if(arr[mid] < arr[right]) {
            right = mid;
        }
    }
    return -1;
}