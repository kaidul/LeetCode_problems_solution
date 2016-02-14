/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // O(n^2)
 /*
class Solution {
    bool isUniValued(TreeNode* root, int val) {
        if(!root) return true;
        if(root->val != val) return false;
        return (isUniValued(root->left, val) && isUniValued(root->right, val));
    }
    
    size_t size(TreeNode* root) const {
        if(!root) return 0;
        return (1 + size(root->left) + size(root->right));
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        if(!root) return 0;
        if(isUniValued(root, root->val)) {
            return size(root);
        }
        return countUnivalSubtrees(root->left) + countUnivalSubtrees(root->right);
    }
};
*/

// O(n)
class Solution {
    bool countUnivalSubtreesRecur(TreeNode* root, int& cnt) {
        if(!root) return true;
        bool isLeft = countUnivalSubtreesRecur(root->left, cnt);
        bool isRight = countUnivalSubtreesRecur(root->right, cnt);
        if(!(isRight and isLeft)) return false;
        if(root->left and root->val != root->left->val) return false;
        if(root->right and root->val != root->right->val) return false;
        cnt++;
        return true;
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        int result = 0;
        countUnivalSubtreesRecur(root, result);
        return result;
    }
};