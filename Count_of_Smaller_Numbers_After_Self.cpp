// O(n^2 logn) solution TLE
/*
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result;
        if(nums.empty()) return result;
        int n = nums.size();
        result.resize(n, 0);
        queue<int> Q;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i = n - 1; i >= 0; i--) {
            minHeap.push(nums[i]);
            
            int cnt = 0;
            while(!minHeap.empty()) {
                int elem = minHeap.top();
                Q.push(elem);
                minHeap.pop();
                if(elem == nums[i]) {
                    result[i] = cnt;
                    break;
                }
                ++cnt;
            }
            
            while(!Q.empty()) {
                minHeap.push(Q.front());
                Q.pop();
            }
        }
        return result;
    }
};
*/

// using set, TLE
/*
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result;
        if(nums.empty()) return result;
        set<int> Set;
        int n = (int)nums.size();
        result.resize(n);
        for(int i = n - 1; i >= 0; --i) {
            auto low = lower_bound(Set.begin(), Set.end(), nums[i]);
            result[i] = distance(Set.begin(), low);
            Set.insert(nums[i]);
        }
        return result;
    }
};
*/

class Solution {
    
    class SegmentTree {
        
        vector<int> segmentNode;
        
    public:
        void init(int n) {
            int N = /* 2 * pow(2, ceil(log((double) n / log(2.0)))) - 1 */ 4 * n;
            segmentNode.resize(N, 0);
        }
        
        void insert(int node, int left, int right, const int indx) {
            if(indx < left or indx > right) {
                return;
            }
            if(left == right and indx == left) {
                segmentNode[node]++;
                return;
            }
            int leftNode = node << 1;
            int rightNode = leftNode | 1;
            int mid = left + (right - left) / 2;
            
            insert(leftNode, left, mid, indx);
            insert(rightNode, mid + 1, right, indx);
            
            segmentNode[node] = segmentNode[leftNode] + segmentNode[rightNode];
        }
        
        int query(int node, int left, int right, const int L, const int R) {
            if(left > R or right < L) {
                return 0;
            }
            if(left >= L and right <= R) {
                return segmentNode[node];
            }
            
            int leftNode = node << 1;
            int rightNode = leftNode | 1;
            int mid = left + (right - left) / 2;
            
            return query(leftNode, left, mid, L, R) + query(rightNode, mid + 1, right, L, R);
        }
        
    };
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result;
        if(nums.empty()) {
            return result;
        }
        int n = nums.size();
        vector<pair<int, int> > data(n);
        for(int i = 0; i < n; ++i) {
            data[i] = pair<int, int>(nums[i], i);
        }
        sort(data.begin(), data.end());
        result.resize(n);
        SegmentTree segmentTree;
        segmentTree.init(n);
        for(int i = 0; i < n; ++i) {
            result[data[i].second] = segmentTree.query(1, 0, n - 1, data[i].second, n - 1);
            segmentTree.insert(1, 0, n - 1, data[i].second);
        }
        return result;
    }
};