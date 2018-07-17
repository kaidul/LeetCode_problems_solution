class Solution {
public:
    int binaryGap(int N) {
        int result = 0;
        int lastOnePos = INT_MIN;
        int k = 0;
        while(N) {
            int r = N % 2;
            if(r) {
                if(lastOnePos != INT_MIN) {
                    result = max(result, k - lastOnePos);
                }
                lastOnePos = k;
            }
            N /= 2;
            k++;
        }
        return result;
    }
};