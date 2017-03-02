class Solution {
public:
    int rob(vector<int> &num) {
        int n = num.size();
        if(n == 0) return 0;
        if(n < 2) return num[0];
        int a = 0, b = 0;
        int tmp;
        for(int i = 0; i < n; ++i) {
            tmp = b;
            b = max(a + num[i], b);
            a = tmp;
        }
        return b;
    }
};