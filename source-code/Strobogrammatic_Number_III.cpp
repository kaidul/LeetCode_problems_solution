class Solution {
    bool Compare(string const& s, string const& low, string const& high) {
        int l1 = (int)low.length();
        int l2 = (int)high.length();
        int l = (int)s.length();
        if((l > l1 or(l == l1 and s >= low)) and (l < l2 or(l == l2 and s <= high))) {
            return true;
        }
        return false;
    }
    int strobogrammaticCount(int left, int right, string& s, string const& low, string const& high) {
        if(left > right) {
            return Compare(s, low, high);
        }
        int ret = 0;
        if((left == 0 and left == right) or left > 0) {
            s[left] = s[right] = '0';
            // if(Compare(s, low, high)) {
                ret += strobogrammaticCount(left + 1, right - 1, s, low, high);
            // }
        }
        s[left] = s[right] = '1';
        // if(Compare(s, low, high)) {
            ret += strobogrammaticCount(left + 1, right - 1, s, low, high);
        // }
        s[left] = s[right] = '8';
        // if(Compare(s, low, high)) {
            ret += strobogrammaticCount(left + 1, right - 1, s, low, high);
        // }
        if(left < right) {
            s[left] = '6'; s[right] = '9';
            // if(Compare(s, low, high)) {
                ret += strobogrammaticCount(left + 1, right - 1, s, low, high);
            // }
            swap(s[left], s[right]);
            // if(Compare(s, low, high)) {
                ret += strobogrammaticCount(left + 1, right - 1, s, low, high);
            // }
        }
        return ret;
    }
public:
    int strobogrammaticInRange(string low, string high) {
        int lowLen = (int)low.length();
        int highLen = (int)high.length();
        int result = 0;
        
        string s;
        s.resize(lowLen, '0');
        result += strobogrammaticCount(0, lowLen - 1, s, low, high);
        
        for(int len = lowLen + 1; len < highLen; ++len) {
            if(len == 1) {
                result += 3;
            } else {
                if(len & 1) {
                    result += (4 * pow(5, len / 2 - 1) * 3);
                } else {
                    result += (4 * pow(5, len / 2 - 1));
                }
            }
        }
        
        if(lowLen != highLen) {
            s.resize(highLen, '0');
            result += strobogrammaticCount(0, highLen - 1, s, low, high);
        }
        
        return result;
    }
};