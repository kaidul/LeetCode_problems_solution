/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p and !q) return true;
        if((!p and q) or (p and !q)) return false;
        return p->val == q->val and isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
};