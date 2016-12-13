class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int moves = 0;
        for(int left = 0, right = nums.size() - 1; left < right; left++, right--) {
            moves += (nums[right] - nums[left]);
        }
        return moves;
    }
};

class Solution {
    
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right], i = left;
        for(int j = left; j < right; ++j) {
            if(nums[j] <= pivot) {
                swap(nums[j], nums[i++]);
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }
    
    int randomPartition(vector<int>& nums, int left, int right) {
        int length = right - left + 1;
        int pivotPos = rand() % length;
        swap(nums[left + pivotPos], nums[right]);
        return partition(nums, left, right);
    }
    
    int SelectionRank(vector<int>& nums, int left, int right, int k) {
        int pivotPos = randomPartition(nums, left, right);
        if(pivotPos == k) {
            return nums[pivotPos];
        }
        if(pivotPos > k) {
            return SelectionRank(nums, left, pivotPos - 1, k);
        }
        return SelectionRank(nums, pivotPos + 1, right, k);
    }
    
public:
    int minMoves2(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        // sort(nums.begin(), nums.end());
        // int median = nums[n / 2];
        int median = SelectionRank(nums, 0, n - 1, (n - 1) / 2);
        int moves = 0;
        for(int i = 0; i < n; i++) {
            moves += abs(nums[i] - median);
        }
        return moves;
    }
};