// linear time with constant space
class Solution {
public:
    bool increasingTriplet(vector<int>& array) {
        int n = array.size();
        if(n < 3) return false;
        // won't work incase of negative numbers. 
        // so in that case, better assign numeric_limits<long>::min()
        int Min = -1;
        int secondMin = -1;
        for (int i = 1; i < n ; i++) {
            if (array[i] > array[i - 1]) {
                if ( Min == -1 and secondMin == -1) {
                    secondMin = i;
                    Min = i - 1;
                } else {
                    if (array[i] > array[secondMin]) {
                        return true;
                    } else if (array[i] < array[secondMin]) {
                        if (array[i] > array[Min]) {
                            secondMin = i;
                        } else if (array[i] < array[Min]) {
                            secondMin = i;
                            Min = i - 1;
                        }
                    }
                }
            } 
        }
        return false;
    }
};
/*
class Solution {
public:
    bool increasingTriplet(vector<int>& arr) {
        int n = arr.size();
        int Min = 0;
        int Max = n - 1;
        vector<int> greater(n, -1);
        vector<int> smaller(n, -1);
        for(int i = 1; i < n; ++i) {
            if(arr[i] <= arr[Min]) {
                Min = i;
            } else {
                greater[i] = Min;
            }
        }
        for(int i = n - 2; i >= 0; --i) {
            if(arr[i] >= arr[Max]) {
                Max = i;
            } else {
                smaller[i] = Max;
            }
        }
        for(int i = 1; i < n - 1; ++i) {
            if(greater[i] != -1 and smaller[i] != -1) {
                return true;
            }
        }
        return false;
    }
};
*/