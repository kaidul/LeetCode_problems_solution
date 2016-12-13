class MedianFinder {
    
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double currMedian = 0.0;
    
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        int leftSize = maxHeap.size();
        int rightSize = minHeap.size();
        int diff = leftSize - rightSize;
        switch(diff) {
        case 0:
            if(num < currMedian) { // or (num <= currMedian)
                maxHeap.push(num);
                currMedian = maxHeap.top();
            } else {
                minHeap.push(num);
                currMedian = minHeap.top();
            }
            break;
        case 1:
            if(num < currMedian) { // or (num <= currMedian)
                maxHeap.push(num);
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else {
                minHeap.push(num);
            }
            currMedian = (maxHeap.top() + minHeap.top()) / 2.0;
            break;
        case -1:
            if(num < currMedian) { // or (num <= currMedian)
                maxHeap.push(num);
            } else {
                minHeap.push(num);
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            currMedian = (maxHeap.top() + minHeap.top()) / 2.0;
            break;
        default:
            break;
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        return currMedian;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();