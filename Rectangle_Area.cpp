class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int ABCD = abs(C - A) * abs(D - B);
        int EFGH = abs(G - E) * abs(H - F);
        
        int intersectedArea = 0;
        if (A < G and C > E and B < H and D > F) {
            int intersectedWidth = abs( max(A, E) - min(C, G) );
            int intersectedHeight = abs( max(B, F) - min(D, H) );
            intersectedArea = intersectedWidth * intersectedHeight;  
        }
        return ABCD + EFGH - intersectedArea;
    }
};