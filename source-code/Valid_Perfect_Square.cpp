class Solution {
public:
	bool isPerfectSquare(int num) {
		if(num == 1) return true;
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
};