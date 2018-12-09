class Solution {
public:
    int numJewelsInStones(string J, string S) {
        vector<bool> isJewel(256, false);
        for (char jewel : J) {
            isJewel[jewel] = true;
        }
        int count = 0;
        for (char stone : S) {
            count += isJewel[stone];
        }
        
        return count;
    }
};