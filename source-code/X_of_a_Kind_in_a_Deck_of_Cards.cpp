class Solution {
    int gcd(int x, int y) {
        return x == 0 ? y : gcd(y % x, x);
    }
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freqMap;
        for(int card : deck) {
            freqMap[card]++;
        }
        int X = -1;
        for(auto entry : freqMap) {
            if(X == -1) {
                X = entry.second;
            } else {
                X = gcd(X, entry.second);
            }
        }
        
        return X >= 2;
    }
};