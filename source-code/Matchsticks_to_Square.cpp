class Solution {
    bool makesquare(int indx, vector<int>& sides, vector<int>& nums, bool& found, const int sideLen) {
        if(found) { return found; }
        if(indx == (int)nums.size()) {
            return found = sides[0] == sideLen and sides[1] == sides[0] and sides[2] == sides[0];
        }
        for(int i = 0; i < (int)sides.size(); i++) {
            if(sides[i] + nums[indx] > sideLen) {
                continue;
            }
            sides[i] += nums[indx];
            if(makesquare(indx + 1, sides, nums, found, sideLen)) {
                return true;
            }
            sides[i] -= nums[indx];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total % 4 != 0 or (int)nums.size() < 4) {
            return false;
        }
        int sideLen = total / 4;
        vector<int> sides(4, 0);
        sort(nums.begin(), nums.end(), greater<int>()); // prune
        bool found = false; // prune
        return makesquare(0, sides, nums, found, sideLen);
    }
};

// another apporoach: DP, not faster here though
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int n = (int)nums.size();
        if(total % 4 != 0 or n < 4) {
            return false;
        }
        int sideLen = total / 4;
        int all = (1 << n) - 1;
        vector<int> validMask;
        unordered_set<int> validHalfMask;
        for(int mask = 1; mask <= all; mask++) {
            int len = 0;
            for(int i = 0; i <= 30; i++) {
                if(mask & (1 << i)) {
                    len += nums[i];
                }
            }
            if(len != sideLen) {
                continue;
            }
            for(int i = 0; i < (int)validMask.size(); i++) {
                if((mask & validMask[i]) == 0) {
                    int halfMask = mask | validMask[i];
                    if(validHalfMask.count(all ^ halfMask) > 0) {
                        return true;
                    }
                    validHalfMask.insert(halfMask);
                }
            }
            validMask.push_back(mask);
        }
        return false;
    }
};