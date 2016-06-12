class Solution {
    static const int dir = 4;
    int dx[dir] = {0, -1, 0, 1};
    int dy[dir] = {-1, 0, 1, 0};
    
    bool isValid(int x, int y, vector<vector<char>> const& image, vector<vector<bool>> const& visited) {
        return (x >= 0 and x < image.size() and y >= 0 and y < image[0].size() and image[x][y] == '1' and !visited[x][y]);    
    }
    
    void minAreaRecur(int x, int y, int& minRow, int& maxRow, int& minCol, int& maxCol, vector<vector<char>> const& image, vector<vector<bool>>& visited) {
        visited[x][y] = true;
        minRow = min(minRow, x);
        maxRow = max(maxRow, x);
        minCol = min(minCol, y);
        maxCol = max(maxCol, y);
        for(int i = 0; i < dir; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(isValid(newX, newY, image, visited)) {
                minAreaRecur(newX, newY, minRow, maxRow, minCol, maxCol, image, visited);
            }
        }
    }
    
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        if(m == 0) return 0;
        int n = image[0].size();
        if(n == 0) return 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int minRow = m - 1;
        int maxRow = 0;
        int minCol = n - 1;
        int maxCol = 0;
        minAreaRecur(x, y, minRow, maxRow, minCol, maxCol, image, visited);
        int area = (maxRow - minRow + 1) * (maxCol - minCol + 1);
        return area;
    }
};