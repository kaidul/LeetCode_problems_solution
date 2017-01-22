class Solution {
public:
    vector<int> constructRectangle(int area) {
        int x = sqrt(area);
        while(x * (area / x) != area) x--;
        return vector<int>{area / x, x};
    }
};