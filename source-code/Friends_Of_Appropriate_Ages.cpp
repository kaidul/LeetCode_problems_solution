class Solution {
    int boundaryIndx(vector<int>& arr, int left, int target) {
        int right = arr.size() - 1;
        int indx = left;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(target < arr[mid]) {
                left = mid + 1;
                indx = mid;
            } else {
                right = mid - 1;
            }
        }
        return indx;
    }
public:
    int numFriendRequests(vector<int>& ages) {
        int result = 0;
        sort(ages.begin(), ages.end(), greater<int>());
        for(int i = 0; i < ages.size(); i++) {
            int bAge = ages[i] / 2 + 7;
            int boundary = boundaryIndx(ages, i, bAge);
            int frndReq = (boundary - i);
            result += frndReq;
            while(i + 1 < ages.size() and ages[i] == ages[i + 1]) {
                result += frndReq;
                i++;
            }
        }
        return result;
    }
};
