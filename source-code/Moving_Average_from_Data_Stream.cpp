class MovingAverage {
    vector<int> nums;
    int n;
    int k;
    int m;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        n = size;
        nums.clear();
        nums.resize(n, 0);
        k = 0; m = 0;
    }
    
    double next(int val) {
        nums[k++] = val;
        if(k == n) k = 0;
        if(m < n) ++m;
        double sum = 0.0;
        for(int i = 0; i < m; ++i) {
            sum += nums[i];
        }
        double avg = sum / (1.0 * m);
        
        return avg;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */