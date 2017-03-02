class Solution {
public:
    string reverseString(string s) {
        for(int n = s.length(), i = 0, k = n - 1; i < k; swap(s[i], s[k]),  ++i, --k);
        return s;
    }
};