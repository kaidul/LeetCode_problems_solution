class MyCircularQueue {
    int frontIndx;
    int rearIndx;
    int maxSize;
    vector<int> container;
    int getSize() {
        return rearIndx - frontIndx + 1;
    }
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        container = vector<int>(k);
        this->frontIndx = 0;
        this->rearIndx = -1;
        this->maxSize = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        }
        container[++rearIndx % maxSize] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) {
            return false;
        }
        frontIndx++;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) {
            return -1;
        }
        return container[frontIndx % maxSize];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) {
            return -1;
        }
        return container[rearIndx % maxSize];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return getSize() == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return getSize() == maxSize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */