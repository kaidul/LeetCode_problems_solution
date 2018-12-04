class RecentCounter {
    queue<int> pingQueue;
public:
    RecentCounter() {
        pingQueue = queue<int> ();
    }
    
    int ping(int t) {
        pingQueue.push(t);
        while(!pingQueue.empty() and t - pingQueue.front() > 3000) {
            pingQueue.pop();
        }
        
        return (int)pingQueue.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */