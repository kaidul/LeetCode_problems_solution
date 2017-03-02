class Solution {
public:
    
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right], i = left;
        for(int j = left; j < right; ++j) {
            if(nums[j] >= pivot) {
                swap(nums[j], nums[i++]);
            }
        }
        swap(nums[i], nums[right]);
        return i;
    }
    
    int randomPartition(vector<int>& nums, int left, int right) {
        int length = right - left + 1;
        int pivotPos = rand() % length;
        swap(nums[left + pivotPos], nums[right]);
        return partition(nums, left, right);
    }
    
    int SelectionRank(vector<int>& nums, int left, int right, int k) {
        int pivotPos = randomPartition(nums, left, right);
        if(pivotPos == k) {
            return nums[pivotPos];
        }
        if(pivotPos > k) {
            return SelectionRank(nums, left, pivotPos - 1, k);
        }
        return SelectionRank(nums, pivotPos + 1, right, k);
    }
    

    int findKthLargest(vector<int>& nums, int k) {
        // O(nlogn)
        /*
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
        */
        
        // O(klogn)
        /*
        priority_queue<int> maxHeap;
        for(int i = 0; i < nums.size(); ++i) {
            maxHeap.push(nums[i]);
        }
        for(int i = 0; i < k - 1; ++i) {
            maxHeap.pop();
        }
        return maxHeap.top();
        */
        
        // O((n - k)log k)
        /*
        priority_queue<int, vector<int>, greater<int> > minHeap;
        for(int i = 0; i < k; ++i) {
            minHeap.push(nums[i]);
        }
        for(int i = k; i < nums.size(); ++i) {
            if(nums[i] > minHeap.top()) {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        return minHeap.top();
        */
        
        // Expexcted O(n)
        int left = 0, right = nums.size() - 1;
        return SelectionRank(nums, left, right, k - 1);
    }
};