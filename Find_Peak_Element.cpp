// linear time
/*
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        for(int i = 0; i < n; ++i) {
            if((i == 0 or num[i] > num[i - 1]) and (i == n - 1 or num[i] > num[i + 1])) {
                return i;
            }
        }
        return 0;
    }
};
*/
// O(logn)
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        int left = 0, right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if((mid == 0 or num[mid] > num[mid - 1]) and (mid == n - 1 or num[mid] > num[mid + 1])) {
                return mid;
            } else {
                if(mid > 0 and num[mid - 1] > num[mid]) {
                    right = mid - 1;
                } else if(mid < n - 1 and num[mid + 1] > num[mid]) {
                    left = mid + 1;
                }
            }
        }
        return -1; // the program won't hit this line
    }
};