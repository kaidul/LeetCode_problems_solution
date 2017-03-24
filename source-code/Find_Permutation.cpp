class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = (int)s.length();
        vector<int> result(n + 1);
        for(int i = 0; i <= n; i++) {
            result[i] = i + 1;
        }
        for(int i = 0; i < n; i++) {
            if(s[i] == 'D') {
                int left = i;
                while(i + 1 < n and s[i + 1] == 'D') {
                    i++;
                }
                reverse(result.begin() + left, result.begin() + i + 2);
            }
        }
        return result;
    }
};