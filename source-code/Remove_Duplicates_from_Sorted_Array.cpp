class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = (int)arr.size();
        if(n == 0) return 0;
        int k = 0, len = 1;
        for(int i = 1; i < n; i++) {
            if(arr[k] != arr[i]) {
                arr[++k] = arr[i];
                len++;
            }
        }
        return len;
    }
};