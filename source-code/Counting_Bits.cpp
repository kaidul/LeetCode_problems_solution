class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;
        int val = 0;
        int prev = 0;
        result.push_back(0);
        while(val < num) {
            int x = 0;
            for(int k = 0; k < 31; ++k) {
                if((bool)(val & (1 << k))) {
                    val &= ~(1 << k);
                    ++x;
                } else {
                    val |= (1 << k);
                    break;
                }
            }
            int curr = prev - x + 1;
            result.push_back(curr);
            prev = curr;
        }
        return result;
    }
};