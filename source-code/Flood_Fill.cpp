class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool isValid(int x, int y, vector<vector<int>> const& image, int colorToFill) {
        return x >= 0 and y >= 0 and x < image.size() and y < image[0].size() and image[x][y] == colorToFill;    
    }
    
    void floodFill(int x, int y, const int colorToFill, const int newColor, vector<vector<int>>& image) {
        image[x][y] = newColor;
        for (int i = 0; i < sizeof(dx) / sizeof(dx[0]); i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(isValid(newX, newY, image, colorToFill)) {
                floodFill(newX, newY, colorToFill, newColor, image); 
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor) return image;
        floodFill(sr, sc, image[sr][sc], newColor, image);
        return image;
    }
};