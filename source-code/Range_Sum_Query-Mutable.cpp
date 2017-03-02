// segment tree AC :)
class NumArray {
    int N;
    vector<int> segmentTree;
    void build(int node, int left, int right, vector<int> const& data) {
        if(left == right) {
            segmentTree[node] = data[left];
            return;
        }
        int leftNode = node << 1;
        int rightNode = leftNode | 1;
        int mid = left + (right - left) / 2;
        build(leftNode, left, mid, data);
        build(rightNode, mid + 1, right, data);
        
        segmentTree[node] = segmentTree[leftNode] + segmentTree[rightNode];
    }
    
    void update(int node, int left, int right, int indx, int val) {
        if(indx < left or indx > right) {
            return;
        }
        if(left == right and indx == left) {
            segmentTree[node] = val;
            return;
        }
        int leftNode = node << 1;
        int rightNode = leftNode | 1;
        int mid = left + (right - left) / 2;
        update(leftNode, left, mid, indx, val);
        update(rightNode, mid + 1, right, indx, val);
        
        segmentTree[node] = segmentTree[leftNode] + segmentTree[rightNode];
    }
    
    int query(int node, int left, int right, int x, int y) {
        if(x > right or y < left) {
            return 0;
        }
        if(left >= x and right <= y) {
            return segmentTree[node];
        }
        
        int leftNode = node << 1;
        int rightNode = leftNode | 1;
        int mid = left + (right - left) / 2;
        return (query(leftNode, left, mid, x, y) + query(rightNode, mid + 1, right, x, y)); 
    }
    
public:
    NumArray(vector<int> &nums) {
        if(nums.empty()) return;
        int length = 2 * pow(2.0, floor(log((double) nums.size() ) / log(2.0)) + 1 );
        segmentTree.clear();
        segmentTree.resize(length, 0);
        N = nums.size();
        build(1, 0, N - 1, nums);
    }

    void update(int i, int val) {
        update(1, 0, N - 1, i, val);
    }

    int sumRange(int i, int j) {
        return query(1, 0, N - 1, i, j);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);