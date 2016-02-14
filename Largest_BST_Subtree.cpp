/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // O(n^2)
 /*
class Solution {
    bool isValidBST(TreeNode* root, long Min, long Max) {
        if(!root) return true;
        if(!(root->val > Min and root->val < Max)) return false;
        return (isValidBST(root->left, Min, root->val) && isValidBST(root->right, root->val, Max));
    }
    
    size_t size(TreeNode* root) const {
        if(!root) return 0;
        return (1 + size(root->left) + size(root->right));
    }
    
public:
    int largestBSTSubtree(TreeNode* root) {
        if(!root) return 0;
        if(isValidBST(root, numeric_limits<long>::min(), numeric_limits<long>::max())) {
            return size(root);
        }
        return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }
};
 */
// O(n)
class Solution {
    bool isValidBST(TreeNode* root, long min, long max) {
        if(!root) return true;
        if(!(root->val > min && root->val < max)) return false;
        return (isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max));
    }
    
    bool largestBSTSubtreeRecur(TreeNode* root, long Min, long Max, int& nodeCnt, int& result) {
        if(!root) return true;
        
        int leftNodeCnt = 0, rightNodeCnt = 0;
        bool isBST = (root->val > Min and root->val < Max);
        isBST &= largestBSTSubtreeRecur(root->left, Min, root->val, leftNodeCnt, result);
        isBST &= largestBSTSubtreeRecur(root->right, root->val, Max, rightNodeCnt, result);
        nodeCnt = 1 + leftNodeCnt + rightNodeCnt;
        
        if(isBST) {
            result = max(result, nodeCnt);
            return true;
        }
        
        bool isLeftBST = isValidBST(root->left, numeric_limits<long>::min(), numeric_limits<long>::max());
        if(isLeftBST) {
            result = max(result, leftNodeCnt);
        }
        bool isRightBST = isValidBST(root->right, numeric_limits<long>::min(), numeric_limits<long>::max());
        if(isRightBST) {
            result = max(result, rightNodeCnt);
        }
        return false;
    }

public:
    int largestBSTSubtree(TreeNode* root) {
        int cnt = 0;
        int result = 0;
        largestBSTSubtreeRecur(root, numeric_limits<long>::min(), numeric_limits<long>::max(), cnt, result);
        return result;
    }
};