class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = (int)arr.size();
        int left = 0, right = n - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] != arr[mid - 1] and arr[mid] != arr[mid + 1]) {
                return arr[mid];
            }
            
            if((mid % 2 == 1 and arr[mid] == arr[mid - 1]) or
                (mid % 2 == 0 and arr[mid] == arr[mid + 1])) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return arr[left];
    }
};