class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = (int)flowerbed.size();
        for(int i = 0; i < m; i++) {
            if(flowerbed[i] == 0) {
                if((i == 0 or flowerbed[i - 1] == 0) and (i == m - 1 or flowerbed[i + 1] == 0)) {
                    flowerbed[i] = 1; n--;
                } 
            }
        }
        return n <= 0;
    }
};