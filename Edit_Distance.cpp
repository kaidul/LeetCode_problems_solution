class Solution {
public:
    int minDistance(string word1, string word2) {
        int lenX = word1.length(), lenY = word2.length();
        int T[lenX + 1][lenY + 1];
        for(int i = 0; i <= lenX; i++) T[i][0] = i;
        for(int i = 0; i <= lenY; i++) T[0][i] = i;
        for(int i = 1; i <= lenX; i++) {
            for(int j = 1; j <= lenY; j++) {
                if (word1[i - 1] == word2[j - 1])
                    T[i][j] = T[i - 1][j - 1];
                else
                    T[i][j] = min(min(T[i - 1][j], T[i][j - 1]), T[i - 1][j - 1]) + 1;
            }
        }
        return T[lenX][lenY];
    }
};