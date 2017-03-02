class Solution {
	const int MOD = 1337;
	
	int superPowUtilRecur(int x, int y) {
		if(y == 0) return 1;
		int ret = superPowUtilRecur(x, y / 2);
		ret = (ret * ret) % MOD;
		if(y & 1) {
			ret = (ret * x) % MOD;
		}
		return ret;
	}
	
	int superPowUtil(int x, int y) {
	    int ret = 1;
	    while(y) {
	        if(y & 1) {
	            ret = (ret * x) % MOD;
	        }
	        x = (x * x) % MOD;
	        y >>= 1;
	    }
	    return ret;
	}
public:
	int superPow(int a, vector<int>& b) {
		int result = 1;
		int pow10 = a % MOD;
		for(int i = (int)b.size() - 1; i >= 0; --i) {
			result = (result * superPowUtil(pow10, b[i])) % MOD;
			pow10 = superPowUtil(pow10, 10);
		}
		
		return result;
	}
};