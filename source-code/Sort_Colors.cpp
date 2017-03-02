// using two pointers
class Solution {
public:
    void sortColors(vector<int>& arr) {
        if(arr.empty()) return;
        int n = arr.size();
        int left = -1, right = 0;
        while(right < n) {
            if(arr[right] == 0) {
                swap(arr[++left], arr[right++]);
            } else {
                ++right;
            }
        }
        right = left + 1;
        while(right < n) {
            if(arr[right] == 1) {
                swap(arr[++left], arr[right++]);
            } else {
                ++right;
            }
        }
    }
};

// counting sort
class Solution {
public:
    void sortColors(int A[], int n) {
        int count[3] = {0};
        for(int i = 0; i < n; ++i) {
            count[A[i]]++;
        }
        int indx = 0;
        for(int i = 0; i < 3; ++i) {
            while(count[i]--) {
                A[indx++] = i;
            }
        }
    }
};