class HitCounter {
#define THRESHOLD 300
    queue <int> hitQueue;
public:
    /** Initialize your data structure here. */
    HitCounter() {
        hitQueue = queue <int> (); 
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        while(!hitQueue.empty() and hitQueue.front() <= timestamp - THRESHOLD) {
            hitQueue.pop();
        }
        hitQueue.push(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while(!hitQueue.empty() and hitQueue.front() <= timestamp - THRESHOLD) {
            hitQueue.pop();
        }
        return (int)hitQueue.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */