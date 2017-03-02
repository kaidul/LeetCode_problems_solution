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
    int longestConsecutiveImpl(TreeNode* root, int& longest) {
        if(!root->left and !root->right) {
            longest = max(longest, 1);
            return 1;
        }
        int seq = 1;
        if(root->left) {
            int leftLen = longestConsecutiveImpl(root->left, longest);
            if(root->left->val == root->val + 1) {
                seq = max(seq, leftLen + 1);
            }
        }
        if(root->right) {
            int rightLen = longestConsecutiveImpl(root->right, longest);
            if(root->right->val == root->val + 1) {
                seq = max(seq, rightLen + 1);
            }
        }
        longest = max(longest, seq);
        
        return seq;
    }
public:
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        int longest = INT_MIN;
        longestConsecutiveImpl(root, longest);
        return longest;
    }
};