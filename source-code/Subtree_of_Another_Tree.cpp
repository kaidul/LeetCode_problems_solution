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
    bool isSameTree(TreeNode* s, TreeNode* t) {
        if(!s and !t) return true;
        if(!s or !t) return false;
        return s->val == t->val and isSameTree(s->left, t->left) and isSameTree(s->right, t->right);    
    }
    
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == nullptr) return false;
        return isSameTree(s, t) or isSubtree(s->left, t) or isSubtree(s->right, t);
    }
};