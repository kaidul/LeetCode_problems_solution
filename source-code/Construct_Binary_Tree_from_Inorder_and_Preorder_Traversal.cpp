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
    TreeNode *treeBuilder(vector<int> &preorder, vector<int> &inorder, int start, int end, int indx) {
        if(start > end) return nullptr;
        
        TreeNode *root = new TreeNode(preorder[indx]);
        int rootPosition;    
        for(int i = start; i <= end; ++i) {
            if(inorder[i] == root->val) {
                rootPosition = i;
                break;
            }
        }
        root->left = treeBuilder(preorder, inorder, start, rootPosition - 1, indx + 1);
        root->right = treeBuilder(preorder, inorder, rootPosition + 1, end, indx + 1 + rootPosition - start);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size() == 0) return nullptr;
        return treeBuilder(preorder, inorder, 0, inorder.size() - 1, 0);
    }
};