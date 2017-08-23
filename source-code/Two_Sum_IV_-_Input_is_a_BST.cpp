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
    void inorder(TreeNode* root, vector<int>& nodes) {
        if(!root) { return; }
        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> nodes;
        inorder(root, nodes);
        int left = 0, right = (int)nodes.size() - 1;
        while(left < right) {
            int sum = nodes[left] + nodes[right];
            if(sum == k) {
                return true;
            }
            if(sum > k) {
                right--;
            } else {
                left++;
            }
        }
        return false;
    }
};