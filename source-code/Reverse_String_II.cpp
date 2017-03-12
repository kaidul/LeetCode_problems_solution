class Solution {
public:
    string reverseStr(string s, int k) {
        int n = (int)s.length();
        int m = k * 2;
        for(int i = 0; i < n; i++) {
            if(i + m - 1 < n) {
                for(int left = i, right = i + k - 1; left < right; left++, right--) {
                    swap(s[left], s[right]);
                }
                i += (m - 1);
            } else {  
                for(int left = i, right = min(i + k - 1, n - 1); left < right; left++, right--) {
                    swap(s[left], s[right]);
                }
                break;
            }
        }
        return s;
    }
};