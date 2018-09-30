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
    TreeNode* constructFromPrePost(int preLeft, int preRight, vector<int>& preOrder, 
                                   int postLeft, int postRight, vector<int>& postOrder) {
        if(preLeft > preRight) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preOrder[preLeft]);
        if(preLeft == preRight) { 
            return root; 
        }
        
        int pivot = -1;
        for(int i = preLeft + 1; i <= preRight; i++) {
            if(preOrder[i] == postOrder[postRight - 1]) {
                pivot = i;
                break;
            }
        }
        root->left = constructFromPrePost(preLeft + 1, pivot - 1, preOrder, 
                                          postLeft, postLeft + pivot - 1 - preLeft - 1, postOrder);
        root->right = constructFromPrePost(pivot, preRight, preOrder, 
                                           postRight - 1 - preRight + pivot, postRight - 1, postOrder);
        
        return root;
    }
    
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return constructFromPrePost(0, pre.size() - 1, pre, 0, post.size() - 1, post);
    }
};