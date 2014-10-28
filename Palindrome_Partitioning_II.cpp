class Solution {
public:
    int minCut(string s) {
        const int SIZE = s.length();
        vector<int> minCuts(SIZE + 1, 0);
        for (int i = 0; i <= SIZE; i++) {
            minCuts[i] = i - 1;
        }
        vector<vector<bool> > isPalFast(SIZE + 1, vector<bool>(SIZE + 1, false));

        for (int j = 2; j <= SIZE; j++) {
            for (int i = 1; i <= j; i++) {
                if (s[i - 1] == s[j - 1] and ((j - i) < 2 or isPalFast[i + 1][j - 1])) {
                    isPalFast[i][j] = true;
                    minCuts[j] = min(minCuts[j], minCuts[i - 1] + 1);
                }
            }
        }
        return minCuts[SIZE];
    }
};