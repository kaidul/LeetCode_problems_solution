class Solution {
    struct SegmentNode {
        long lower;
        long upper;
        int count;
        SegmentNode() {}
        SegmentNode(long l, long r): lower(l), upper(r), count(0) {}
    };
    
    class SegmentTree{
        
        vector<SegmentNode> segmentNodes;
        int n;
        
        void build(int node, int left, int right, vector<long>& nums) {
            
            segmentNodes[node] = SegmentNode(nums[left], nums[right]);
            
            if(left == right) {
                return;
            }
            
            int leftNode = node << 1;
            int rightNode = leftNode | 1;
            int mid = left + (right - left) / 2;
            
            build(leftNode, left, mid, nums);
            build(rightNode, mid + 1, right, nums);
        }
        
        void update(int node, int left, int right, long val) {
            if(val < segmentNodes[node].lower or val > segmentNodes[node].upper) {
                return;
            }
            
            segmentNodes[node].count++;
            
            if(left == right) {
                return;
            }
            
            int leftNode = node << 1;
            int rightNode = leftNode | 1;
            int mid = left + (right - left) / 2;
            
            update(leftNode, left, mid, val);
            update(rightNode, mid + 1, right, val);
        }
        
        int query(int node, int left, int right, const long lower, const long upper) {
            if(upper < segmentNodes[node].lower or lower > segmentNodes[node].upper) {
                return 0;
            }
            if(segmentNodes[node].lower >= lower and segmentNodes[node].upper <= upper) {
                return segmentNodes[node].count;
            }
            
            int leftNode = node << 1;
            int rightNode = leftNode | 1;
            int mid = left + (right - left) / 2;
            
            return query(leftNode, left, mid, lower, upper) + query(rightNode, mid + 1, right, lower, upper);
        }
        
    public:
        void init(vector<long>& nums) {
            n = (int)nums.size();
            int N = 2 * pow(2, ceil(log((double)n) / log(2.0)) + 1) - 1;
            segmentNodes.resize(N);
            build(1, 0, n - 1, nums);
        }
        
        void update(long val) {
            update(1, 0, n - 1, val);
        }
        
        int query(long lower, long upper) {
            return query(1, 0, n - 1, lower, upper);
        }
    };
    
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.empty()) return 0;
        int n = (int)nums.size();
        vector<long> sums;
        set<long> values;
        long sum = 0L;
        for(int i = 0; i < (int)nums.size(); ++i) {
            sum += nums[i];
            values.insert(sum);
        }
        for(auto it = values.begin(); it != values.end(); ++it) {
            sums.push_back(*it);
        }
        
        int result = 0;
        SegmentTree segmentTree;
        segmentTree.init(sums);
        for(int i = n - 1; i >= 0; --i) {
            segmentTree.update(sum);
            sum -= nums[i];
            result += segmentTree.query(lower + sum, upper + sum);
        }
        return result;
    }
};