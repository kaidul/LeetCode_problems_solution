class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        for(int i = 0, j = 0; i < A.length(); ++i) {
            for(j = 0; j < B.length() and A[(i + j) % A.length()] == B[j]; ++j);
            if(j == B.length()) {
                return (i + j) / A.length() + ((i + j) % A.length() != 0);    
            }
        }
        return -1;
    }
};