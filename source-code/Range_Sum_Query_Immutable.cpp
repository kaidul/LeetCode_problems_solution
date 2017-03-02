class NumArray {
public:
    vector<int> cumSum;
    NumArray(vector<int> &nums) {
        if(nums.size() < 1) return;
        cumSum.resize(nums.size(), 0);
        cumSum[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            cumSum[i] = cumSum[i - 1] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return (cumSum[j] - ((i > 0) ? cumSum[i - 1] : 0));
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);