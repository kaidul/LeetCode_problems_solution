class Solution {
public:
    vector<int> segmentTree;
    vector<int> histogram;
    int n;
    void init() {
        segmentTree.clear();
        const int SIZE  = pow(2, ceil(log((double) n) / log(2.0)) + 1) - 1;
        segmentTree.resize(SIZE, 0);
        build(1, 0, n - 1);
    }
    
    // O(n)
    int build(int node, int left, int right) {
        if(left == right) {
            return segmentTree[node] = left;
        }
        int leftNode = node << 1;
        int rightNode = leftNode | 1;
        int mid = left + (right - left) / 2;
        int leftIdx = build(leftNode, left, mid);
        int rightIdx = build(rightNode, mid + 1, right);
        return segmentTree[node] = (histogram[leftIdx] <= histogram[rightIdx]) ? leftIdx : rightIdx;
    }
    
    int query(int node, int left, int right, int x, int y) {
        if(x > right or y < left) return -1;
        if(left >= x and right <= y) return segmentTree[node];
        int leftNode = node << 1;
        int rightNode = leftNode | 1;
        int mid = left + (right - left) / 2;
        int leftIdx = query(leftNode, left, mid, x, y);
        int rightIdx = query(rightNode, mid + 1, right, x, y);
        if(leftIdx == -1) return rightIdx;
        if(rightIdx == -1) return leftIdx;
        return (histogram[leftIdx] <= histogram[rightIdx]) ? leftIdx : rightIdx;
    }
    
    int query(int x, int y) {
        return query(1, 0, n - 1, x, y);
    }
    
    // O(n logn)
    int largestRectangleArea(int left, int right) {
        if(left > right) return INT_MIN;
        int mid = query(left, right); // O(logn)
        int leftContent = largestRectangleArea(left, mid - 1);
        int rightContent = largestRectangleArea(mid + 1, right);
        return max(histogram[mid] * (right - left + 1), max(leftContent, rightContent));
    }
    
    int largestRectangleArea(vector<int>& height) {
        this->histogram = height;
        this->n = height.size();
        if(n == 0) return 0;
        init();
        return largestRectangleArea(0, n - 1);
    }
};