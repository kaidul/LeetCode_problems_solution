// O(n^2) dynamic programming
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = (int)nums.size();
        vector<int> pos(n, 1);
        vector<int> neg(n, 1);
        int maxLength = max(pos[0], neg[0]);
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] > nums[j]) {
                    pos[i] = max(pos[i], neg[j] + 1);
                } else if(nums[i] < nums[j]) {
                    neg[i] = max(neg[i], pos[j] + 1);
                }
            }
            maxLength = max(pos[i], neg[i]);
        }
        
        return maxLength;
    }
};

// O(n) dp
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = (int)nums.size();
        if(n == 0) return n;
        vector<int> down(n, 0), up(n, 0);
        down[0] = up[0] = 1;
        for(int i = 1; i < n; ++i) {
            if(nums[i] > nums[i - 1]) {
                up[i] = down[i - 1] + 1;
                down[i] = down[i - 1];
            } else if(nums[i] < nums[i - 1]) {
                up[i] = up[i - 1];
                down[i] = up[i - 1] + 1;
            } else {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }
        return max(up[n - 1], down[n - 1]);
    }
};

// O(n) greedy
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = (int)nums.size();
        if(n == 0) return 0;
        int up = 1, down = 1;
        for(int i = 1; i < n; ++i) {
            if(nums[i] > nums[i - 1]) {
                up = down + 1;
            } else if(nums[i] < nums[i - 1]) {
                down = up + 1;
            }
        }
        return max(up, down);
    }
};