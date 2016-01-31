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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(!p and !q) return true;
        if((!p and q) or (p and !q)) return false;
        /*
        if((p and !p->left and !p->right) and (q and !q->left and !q->right))
            if(p->val == q->val)
                return true;
            else 
                return false;
        if(p->val == q->val) {
            return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
        } else
            return false;
        */
        if(p->val != q->val) return false;
        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right); 
    }
};