// didn't satisfy "firstly find the number occurs twice and then find the number that is missing"
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int Xor = 0;
        for(int i = 0, k = 1; i < nums.size(); i++, k++) {
            Xor ^= nums[i];
            Xor ^= k;
        }
        vector<int> result;
        for(int i = 0; i < 31; i++) {
            if(Xor & (1 << i)) {
                int X = 0;
                for(int k = 1; k <= nums.size(); k++) {
                    if(k & (1 << i)) {
                        X ^= k;
                    }    
                }
                result.push_back(X);
                int Y = Xor ^ X;
                result.push_back(Y);
                break;
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[abs(nums[i]) - 1] > 0) {
                nums[abs(nums[i]) - 1] *= -1;
            } else {
                result.push_back(abs(nums[i]));
            }
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};