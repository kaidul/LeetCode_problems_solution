/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    class SegmentTree {
        vector<int> segmentTree;
        vector<int> arr;
        int n;
    public:
        SegmentTree(vector<int>& arr) {
            this->arr = arr;
            this->n = (int)arr.size();
            int N = 2 * pow(2.0, floor(log((double) n) / log(2.0)) + 1);
            segmentTree = vector<int>(N, 0);
        }
        
        int build(int node, int left, int right) {
            if(left > right) {
                return -1;
            }
            if(left == right) {
                return segmentTree[node] = left;
            }
            
            int mid = left + (right - left) / 2;
            int leftNode = node << 1, rightNode = leftNode | 1;
            int leftIndx = build(leftNode, left, mid);
            int rightIndx = build(rightNode, mid + 1, right);
        
            return segmentTree[node] = arr[leftIndx] > arr[rightIndx] ? leftIndx : rightIndx;
        }
        
        void build() {
            build(1, 0, (int)arr.size() - 1);
        }
        
        int query(int node, int left, int right, const int lower, const int upper) {
            if(lower > right or upper < left or left > right) {
                return -1;
            }
            if(left >= lower and right <= upper) {
                return segmentTree[node];
            }
            int mid = left + (right - left) / 2;
            int leftNode = node << 1, rightNode = leftNode | 1;
            int leftIndx = query(leftNode, left, mid, lower, upper);
            int rightIndx = query(rightNode, mid + 1, right, lower, upper);
            if(leftIndx == -1) {
                return rightIndx;
            }
            if(rightIndx == -1) {
                return leftIndx;
            }
            
            return arr[leftIndx] > arr[rightIndx] ? leftIndx : rightIndx;
        }
        
        int query(int lower, int upper) {
            return query(1, 0, n - 1, lower, upper);
        }
    };
    TreeNode* constructMaximumBinaryTree(int left, int right, SegmentTree* segTree, vector<int>& nums) {
        if(left > right) {
            return nullptr;
        }
        if(left == right) {
            return new TreeNode(nums[left]);
        }
        int rootIndx = segTree->query(left, right);
        TreeNode* root = new TreeNode(nums[rootIndx]);
        root->left = constructMaximumBinaryTree(left, rootIndx - 1, segTree, nums);
        root->right = constructMaximumBinaryTree(rootIndx + 1, right, segTree, nums);
        
        return root;
    }
    
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = (int)nums.size();
        SegmentTree* segTree = new SegmentTree(nums);
        segTree->build();
        TreeNode* root = constructMaximumBinaryTree(0, n - 1, segTree, nums);
        delete segTree;
        return root;
    }
};