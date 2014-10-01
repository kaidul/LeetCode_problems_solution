class Solution {
public:
    int numDistinct(string S, string T) {

        vector<int> f(T.length() + 1);

        f[T.length()] = 1;

        for(int i = S.length() - 1; i >= 0; --i) {
            for(int j = 0; j < T.length(); ++j) {
                f[j] += (S[i] == T[j]) * f[j + 1];
            }
        }
        return f[0];
    }
};