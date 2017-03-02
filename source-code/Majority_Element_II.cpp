class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int countA = 0;
        int countB = 0;
        int A, B;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if((countA == 0 and B != nums[i]) or A == nums[i]) {
                ++countA;
                A = nums[i];
            } else if(countB == 0 or B == nums[i]) {
                ++countB;
                B = nums[i];
            } else {
                --countA;
                --countB;
            }
        }
        countA = countB = 0;
        for(int i = 0; i < n; ++i) {
            countA += (A == nums[i]);
            countB += (B == nums[i]);
        }
        vector<int> result;
        if(countA > floor(n / 3)) {
            result.push_back(A);
        }
        if(countB > floor(n / 3)) {
            result.push_back(B);
        }
        return result;
    }
};