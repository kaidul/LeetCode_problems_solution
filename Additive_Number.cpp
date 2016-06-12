class Solution {
	typedef long long int64;
	
	int64 toInt64(string s) {
		int64 n = 0LL;
		istringstream sin(s);
		sin >> n;
		return n;
	}
	
	string toString(int64 n) {
		ostringstream oss;
		oss << n;
		oss.flush();
		return oss.str();
	}
	
	bool isAdditiveNumber(int indx, string const& s, int64 a, int64 b, int seqLen, bool& found) {
		if(found) { return true; }
		if(indx == (int)s.length()) {
			return found = (seqLen >= 3);
		}
		if(a == LLONG_MIN) {
			if(s[indx] == '0') {
				a = 0LL;
				return isAdditiveNumber(indx + 1, s, a, b, seqLen + 1, found);
			}
			for(int i = indx + 1; i <= (int)s.length(); ++i) {
				a = toInt64(s.substr(indx, i - indx));
				if(isAdditiveNumber(i, s, a, b, seqLen + 1, found)) {
					return true;
				}
			}
			return false;
		}
		if(b == LLONG_MIN) {
			if(s[indx] == '0') {
				b = 0LL;
				return isAdditiveNumber(indx + 1, s, a, b, seqLen + 1, found);
			}
			for(int i = indx + 1; i <= (int)s.length(); ++i) {
				b = toInt64(s.substr(indx, i - indx));
				if(isAdditiveNumber(i, s, a, b, seqLen + 1, found)) {
					return true;
				}
			}
			return false;
		}
		int64 sum = a + b;
		string sSum = toString(sum);
		int len = (int)sSum.length();
		if(s.substr(indx, len) != sSum) {
			return false;
		}
		return isAdditiveNumber(indx + len, s, b, sum, seqLen + 1, found);
	}
	
public:
	bool isAdditiveNumber(string num) {
		if(num.empty()) return false;
		int64 a = LLONG_MIN, b = LLONG_MIN;
		bool found = false;
		return isAdditiveNumber(0, num, a, b, 0, found);
	}
};