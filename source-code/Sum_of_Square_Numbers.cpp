class Solution {
    bool isPerfectSquare(int num) {
		if(num <= 1) return true;
		long long left = 2LL, right = num / 2LL;
		while(left <= right) {
			long long mid = left + (right - left) / 2LL;
			long long square = mid * mid;
			if(square == num) {
				return true;
			}
			if(square > num) {
				right = mid - 1LL;
			} else {
				left = mid + 1LL;
			}
		}
		return false;
	}
public:
    bool judgeSquareSum(int c) {
        if(c == 0) return true;
        int a = 1;
        while(a <= c / a) {
            int bSquare = c - a * a;
            if(isPerfectSquare(bSquare)) {
                return true;
            }
            a++;
        }
        
        return false;
    }
};