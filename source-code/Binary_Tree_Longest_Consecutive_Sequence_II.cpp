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
    pair<int, int> longestConsecutive(TreeNode* root, int& longest) {
        if (!root->left and !root->right) {
            longest = max(longest, 1);
            return {1, 1};
        }
        int incrSeqLeftLen = 1, decSeqLeftLen = 1, incrSeqRightLen = 1, decSeqRightLen = 1;
        if (root->left) {
            pair<int, int> leftSeqLen = longestConsecutive(root->left, longest);
            if (root->left->val + 1 == root->val) {
                incrSeqLeftLen = max(incrSeqLeftLen, leftSeqLen.first + 1);
            } else if (root->left->val == root->val + 1) {
                decSeqLeftLen = max(decSeqLeftLen, leftSeqLen.second + 1);
            }
        }
        
        if (root->right) {
            pair<int, int> rightSeqLen = longestConsecutive(root->right, longest);
            if (root->right->val + 1 == root->val) {
                incrSeqRightLen = max(incrSeqRightLen, rightSeqLen.first + 1);
            } else if (root->right->val == root->val + 1) {
                decSeqRightLen = max(decSeqRightLen, rightSeqLen.second + 1);
            }
        }
        
        longest = max(longest, max(incrSeqLeftLen + decSeqRightLen - 1, decSeqLeftLen + incrSeqRightLen - 1));
        
        return {max(incrSeqLeftLen, incrSeqRightLen), max(decSeqLeftLen, decSeqRightLen)};
    }
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        int longest = INT_MIN;
        longestConsecutive(root, longest);
        
        return longest;
    }
};