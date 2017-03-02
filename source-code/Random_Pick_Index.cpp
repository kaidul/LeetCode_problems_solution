// Reservoir sampling: http://www.geeksforgeeks.org/reservoir-sampling/
class Solution {
    vector<int> arr;
    // default_random_engine generator;
public:
    Solution(vector<int> nums) {
        srand(time(NULL));
        arr = nums;
        // generator = default_random_engine();
    }
    
    int pick(int target) {
        int result = -1, cnt = 0;
        for(int i = 0; i < arr.size(); ++i) {
            if(arr[i] != target) {
                continue;
            }
            if(cnt == 0) { result = i; cnt++; }
            else { cnt++; if(rand() % cnt == 0) result = i; }
            // AC but TLE :(
            /*
            uniform_int_distribution<int> distribution(0, cnt); // will geenrate random number between [0, cnt]
            if(distribution(generator) == cnt) {
                result = i;
            }
            ++cnt;
            */
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */