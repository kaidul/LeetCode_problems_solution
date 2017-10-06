class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int val : nums) {
            freq[val]++;
        }
        unordered_map<int, int> tail;
        for(int val : nums) {
            if(!freq[val]) {
                continue;
            }
            freq[val]--;
            if(tail[val - 1]) {
                tail[val - 1]--;
                tail[val]++;
            } else if(freq[val + 1] and freq[val + 2]) {
                freq[val + 1]--;
                freq[val + 2]--;
                tail[val + 2]++;
            } else {
                return false;
            }
        }
        return true;
    }
};