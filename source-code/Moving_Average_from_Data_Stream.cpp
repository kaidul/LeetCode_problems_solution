class MovingAverage {
    deque<int> window;
    int sum;
    int maxLength;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sum = 0;
        maxLength = size;
        window = deque<int>();
    }
    
    double next(int val) {
        sum += val;
        window.push_back(val);
        if(window.size() > maxLength) {
            sum -= window.front();
            window.pop_front();
        }
        return sum / (1.0 * window.size());
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */