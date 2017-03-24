class Solution {
public:
    string findContestMatch(int n) {
        vector<string> match;
        for(int i = 1; i <= n; i++) {
            match.push_back(to_string(i));
        }
        while(n) {
            for(int i = 0, j = n - 1; i < j; i++, j--) {
                match[i] = "(" + match[i] + "," + match[j] + ")";
            }
            n /= 2;
        }
        return match[0];
    }
};