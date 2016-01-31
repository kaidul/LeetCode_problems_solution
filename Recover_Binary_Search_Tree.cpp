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
    void recoverTreeUtils(TreeNode *root, TreeNode **prev, TreeNode **p, TreeNode **q) {
        if(!root) return;
        
        recoverTreeUtils(root->left, prev, p, q);
        
        if(root->val <= (*prev)->val) {
            if(*p == nullptr) {
                *p = *prev;
            }
            *q = root;
        }
        *prev = root;
        
        recoverTreeUtils(root->right, prev, p, q);
    }
    void recoverTree(TreeNode *root) {
        TreeNode *p = nullptr, *q = nullptr;
        TreeNode *prev = new TreeNode(numeric_limits<int>::min());
        recoverTreeUtils(root, &prev, &p, &q);
        int tmp = p->val;
        p->val = q->val;
        q->val = tmp;
    }
};