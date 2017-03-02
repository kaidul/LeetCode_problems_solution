class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> result;
        if(length == 0) return result;
        result.resize(length, 0);
        for(int i = 0; i < (int)updates.size(); ++i) {
            int startIndx = updates[i][0];
            int endIndx = updates[i][1];
            int value = updates[i][2];
            
            result[startIndx] += value;
            if(endIndx + 1 < length) {
                result[endIndx + 1] -= value;
            }
        }
        int k = 0;
        for(int i = 0; i < (int)result.size(); ++i) {
            int tmp = result[i];
            result[i] += k;
            k += tmp;
        }
        
        return result;
    }
};