class Solution {
public:
    int sqrt(int x) {
        long long high = x;
        long long low = 0;
        if (x <= 0) {return 0;}
        if (x == 1) {return 1;}
        while (high - low > 1)  {
            long long mid = low + (high - low) / 2;
            if (mid * mid <= x){ low = mid; }
            else { high = mid; }
        }
        return low;
    }
};

// no hassle of overflow
class Solution {
public:
    int sqrt(int x) {
        if (x == 0) return 0;
        int start = 1, end = x, ans;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (mid <= x / mid) {
                start = mid + 1;
                ans = mid;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};