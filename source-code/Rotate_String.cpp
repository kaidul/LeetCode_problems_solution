class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.length() != B.length())
            return false;
        if(A.empty())
            return true;
        int n = A.length();
        for(int i = 0; i < n; i++) {
            bool flag = true;
            for(int k = 0, j = i; k < n and flag; j++, k++) {
                int indx = j % n;
                if(A[k] != B[indx]) {
                    flag = false;
                }
            }
            if(flag) return true;
        }
        return false;
    }
};