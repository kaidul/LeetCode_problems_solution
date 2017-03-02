class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.length();
        int maxLen = 0;
        const int MAX_DEPTH = 20; // enough for this problem
        vector<int> level(MAX_DEPTH);
        level[0] = 0;
        for(int i = 0; i < n; ++i) {
            int depth = 1;
            while(i < n and input[i] == '\t') {
                depth++;
                ++i;
            }
            bool isFile = false;
            int keyLen = 0;
            while(i < n and input[i] != '\n') {
                isFile |= (input[i] == '.');
                ++i; ++keyLen;
            }
            if(isFile) {
                maxLen = max(maxLen, level[depth - 1] + keyLen);
            } else {
                level[depth] = level[depth - 1] + keyLen;
                level[depth]++; // for '/'
            }
        }
        return maxLen;
    }
};