class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty()) return;
        reverse(s.begin(), s.end());
        for(int i = 0; i < s.length();) {
            int pos = s.find(' ', i);
            if(pos == string::npos) {
                pos = s.length();
            }
            int left = i, right = pos - 1;
            while(left < right) {
                swap(s[left++], s[right--]);
            }
            i = pos + 1;
        }
    }
};