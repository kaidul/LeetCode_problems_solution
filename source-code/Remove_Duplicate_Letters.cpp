class Solution {
#define MAX 26
public:
    string removeDuplicateLetters(string s) {
        if(s.empty() or s.length() == 1) return s;
        int n = s.length();
        stack<char> Stack;
        vector<int> taken(MAX, false);
        vector<int> freq(MAX, 0);
        for(int i = 0; i < n; ++i) {
            freq[s[i] - 'a']++;
        }
        for(int i = 0; i < n; ++i) {
            if(!taken[s[i] - 'a']) {
                while(!Stack.empty() and Stack.top() > s[i] and freq[Stack.top() - 'a'] > 0) {
                    char rmv = Stack.top();
                    Stack.pop();
                    taken[rmv - 'a'] = false;
                }
                Stack.push(s[i]);
                taken[s[i] - 'a'] = true;
            }
            freq[s[i] - 'a']--;
        }
        string result = "";
        result.reserve(Stack.size());
        while(!Stack.empty()) {
            result = Stack.top() + result;
            Stack.pop();
        }
        return result;
    }
};
// Complete search TLE
/*
class Solution {
    void removeDuplicateLettersRecur(int indx, string const& s, const int freq[], bool taken[], string& out, const int len, string& result) {
        if(indx == s.length()) {
            if(out.length() == len) {
                if(result.empty()) result = out;
                else result = min(result, out);    
            }
            return;
        }
        if(freq[s[indx] - 'a'] > 1) {
            if(!taken[s[indx] - 'a']) {
                out += s[indx];
                taken[s[indx] - 'a'] = true;
                removeDuplicateLettersRecur(indx + 1, s, freq, taken, out, len, result);
                out.erase(out.length() - 1, 1);
                taken[s[indx] - 'a'] = false;    
            }
            removeDuplicateLettersRecur(indx + 1, s, freq, taken, out, len, result);
        } else {
            out += s[indx];
            removeDuplicateLettersRecur(indx + 1, s, freq, taken, out, len, result);
            out.erase(out.length() - 1, 1);
        }
    }
    
public:
    string removeDuplicateLetters(string s) {
        int freq[30] = {0};
        int len = 0;
        for(int i = 0; i < s.length(); ++i) {
            if(!freq[s[i] - 'a']) ++len;
            freq[s[i] - 'a']++;
        }
        bool taken[30] = {false};
        string out = "";
        string result = "";
        removeDuplicateLettersRecur(0, s, freq, taken, out, len, result);
        return result;
    }
};
*/