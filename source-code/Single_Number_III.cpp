class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        if(n == 0) return result;
        int Xor = nums[0];
        for(int i = 1; i < n; ++i) {
            Xor ^= nums[i];
        }
        
        /*
        int mask = 1;
        while ((mask & Xor) == 0) {
            mask = mask << 1;
        }
        */
        int mask = (Xor & -Xor);
        
        int xor1 = 0;
        int xor2 = 0;
         
        for (int i = 0; i < n; ++i) {
            if ((nums[i] & mask) == 0) {
                xor1 ^= nums[i];
            } else {
                xor2 ^= nums[i];
            }
        }
        result.push_back(xor1);
        result.push_back(xor2);
        return result;
    }
};