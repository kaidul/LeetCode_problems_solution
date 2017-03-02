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
    TreeNode *treeBuilder(vector<int> &inorder, vector<int> &postorder, int start, int end, int indx) {    
            if (start > end) return NULL;
            TreeNode *curr_root = new TreeNode(postorder[indx]);
            int rootIndx;
            for (int i = start; i <= end; i++) {
                if (inorder[i] == curr_root->val) { 
                    rootIndx = i;
                    break;
                }
            }
            curr_root->right = treeBuilder(inorder, postorder, rootIndx + 1, end , indx - 1);
            curr_root->left = treeBuilder(inorder, postorder, start, rootIndx - 1, indx - 1 - end + rootIndx);
            return curr_root;
    }
 
 
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.size() == 0)
            return nullptr;
        return treeBuilder(inorder, postorder, 0, inorder.size() - 1, postorder.size() - 1);
    }    
};