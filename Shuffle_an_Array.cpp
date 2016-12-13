// Fisher Yates algorithm
class Solution {
    vector<int> original;
    vector<int> arr;
public:
    Solution(vector<int> nums) {
        srand(time(NULL));
        arr = nums;
        original = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return arr = original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i = arr.size() - 1; i > 0; --i) {
            int j = rand() % (i + 1);
            swap(arr[i], arr[j]);
        }
        return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */