class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = (int) ratings.size();
        vector<int> lc(n, 1);
        vector<int> rc(n, 1);
        int res = 0;
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                lc[i] = lc[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                rc[i] = rc[i + 1] + 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            res += max(lc[i], rc[i]);
        }
        return res;
    }
};