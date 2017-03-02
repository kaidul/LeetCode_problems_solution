// using the idea of longest prefix suffix
// http://yucoding.blogspot.sg/2015/10/leetcode-question-shortest-palindrome.html
class Solution {
    int computeLps(string s) {
        vector<int>lps(s.length(), 0);
        int len = 0;
        int i = 1;
        int n = s.length();
        while(i < n) {
            if(i == (n - 1) / 2) {
                ++i; // skip
            } else if(s[len] == s[i]) {
                lps[i++] = ++len;
            } else {
                if(len > 0) {
                    len = lps[len - 1];
                } else {
                    len = 0;
                    lps[i++] = len;
                }
            }
        }
        return lps[s.length() - 1];
    }
public:
    string shortestPalindrome(string s) {
        if(s.length() <= 1) return s;
        string reverseS = s;
        reverse(reverseS.begin(), reverseS.end());
        int m = computeLps(s + reverseS);
        if(m >= s.length()) {
            return s;
        }
        string prefix = s.substr(m);
        reverse(prefix.begin(), prefix.end());
        return prefix + s;
    }
};

// TLE too. similiar solution is AC in java. Leetcode OJ is such a racist :)
class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.empty() or s.length() == 1) return s;
        int n = s.length();
        int maxLen = 0;
        int left, right;
        int len;
        for(int i = 0; i < n; ++i) {
            left = i - 1;
            right = i + 1;
            while(left >= 0 and right < n and s[left] == s[right]) {
                --left;
                ++right;
            }
            len = right - left - 1;
            if(left < 0 and len > maxLen) {
                maxLen = len;
            }
            
            left = i;
            right = i + 1;
            while(left >= 0 and right < n and s[left] == s[right]) {
                --left;
                ++right;
            }
            len = right - left - 1;
            if(left < 0 and len > maxLen) {
                maxLen = len;
            }
        }
        string result;
        for(int i = n - 1; i >= maxLen; --i) {
            result += s[i];
        }
        result.append(s);
        return result;
    }
};
// TLE
/*
class Solution {
    bool isPalindrome(string& s, int left, int right) {
        while(left < right) {
            if(s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
public:
    string shortestPalindrome(string s) {
        if(s.empty() or s.length() == 1) return s;
        int n = s.length();
        for(int left = 0, right = n - 1; left <= right; --right) {
            if(s[left] == s[right]) {
                if(isPalindrome(s, left + 1, right - 1)) {
                    // string prefix = s.substr(right + 1);
                    // reverse(prefix.begin(), prefix.end());
                    // string result = prefix + s;
                    string result;
                    result.reserve(n + n - right);
                    for(int k = n - 1; k > right; --k) {
                        result += s[k];
                    }
                    result += s;
                    return result;
                }
            }
        }
    }
};
*/