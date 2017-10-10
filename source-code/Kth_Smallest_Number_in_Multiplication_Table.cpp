class Solution {
    bool largerEnough(int x, int m, int n, int k) {
        int count = 0;
        for(int i = 1; i <= m; i++) {
            count += min(x / i, n);
        }
        return count >= k;
    }
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(!largerEnough(mid, m, n, k)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};