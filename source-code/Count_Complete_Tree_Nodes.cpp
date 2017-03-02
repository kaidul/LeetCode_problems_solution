/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // TLE
 /*
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        return 1 + left + right;
    }
};
*/

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
    int getCompleteNodesCount(TreeNode* root, int& height) {
        int level = 0;
        TreeNode* node = root;
        while(node->right) {
            ++level;
            node = node->right;
        }
        height = level + 1;
        return (pow(2, height) - 1);
    }
    
    int getInCompleteNodesCount(TreeNode* root, int depth, const int height, bool& done) {
        if(done) { return 0; }
        if(depth == height) {
            if(!root->left or !root->right) {
                done = true;
            }
            return ((root->left != nullptr) + (root->right != nullptr));
        }
        return getInCompleteNodesCount(root->left, depth + 1, height, done) +
                getInCompleteNodesCount(root->right, depth + 1, height, done);
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int height;
        int result = getCompleteNodesCount(root, height);
        bool done = false;
        result += getInCompleteNodesCount(root, 1, height, done);
        
        return result;
    }
};