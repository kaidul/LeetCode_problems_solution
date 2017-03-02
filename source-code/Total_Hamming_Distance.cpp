class Solution {
public:
    int totalHammingDistance(vector<int>& arr) {
        int n = arr.size();
        int diff = 0;
        for(int i = 0; i < 31; i++) {
            int on = 0;
            for(int k = 0; k < n; k++) {
                if(arr[k] & (1 << i)) {
                    on++;
                }
            }
            int off = n - on;
            diff += (on * off);
        }
        return diff;
    }
};