class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result;
        if(k > n - 1) {
            return result;
        }
        int left = 1, right = n;
        for(int i = 0, flip = 0; i < n; i++, flip ^= 1) {
            if(k == 1) {
                if(flip) {
                    for(int i = right; i >= left; i--) {
                        result.push_back(i);
                    }
                } else {
                    for(int i = left; i <= right; i++) {
                        result.push_back(i);
                    }
                }
                break;
            }
            if(i > 0) { k--; }
            result.push_back(flip ? left++ : right--);
        }
        return result;
    }
};