class KthLargest {
    int size;
    priority_queue <int, vector<int>, greater<int>> pQ;
public:
    KthLargest(int k, vector<int> nums) {
        pQ = priority_queue <int, vector<int>, greater<int>> ();
        this->size = k;
        if(nums.empty()) {
            return;
        }
        for (int i = 0; i < min(k, (int)nums.size()); i++) {
            pQ.push(nums[i]);
        }
        for(int i = k; i < nums.size(); i++) {
            if(nums[i] > pQ.top()) {
                pQ.pop();
                pQ.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(pQ.empty() or pQ.size() < size) {
            pQ.push(val);
        } else if(val > pQ.top()) {
            pQ.pop();
            pQ.push(val);
        }
        return pQ.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */