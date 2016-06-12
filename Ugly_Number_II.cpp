class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNums(n, 0);
        uglyNums[0] = 1;
        int i2, i3, i5;
        i2 = i3 = i5 = 0; 
        int nextUgly2 = 2;
        int nextUgly3 = 3;
        int nextUgly5 = 5;
        int nextUglyNo = 1;
        for(int i = 1; i < n; ++i) {
            nextUglyNo = min(min(nextUgly2, nextUgly3), nextUgly5);
            uglyNums[i] = nextUglyNo;
            if(nextUglyNo == nextUgly2) {
                nextUgly2 = uglyNums[++i2] * 2;
            }
            if(nextUglyNo == nextUgly3) {
                nextUgly3 = uglyNums[++i3] * 3;
            }
            if(nextUglyNo == nextUgly5) {
                nextUgly5 = uglyNums[++i5] * 5;
            }
        }
        return nextUglyNo;
    }
};