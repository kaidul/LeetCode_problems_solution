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

// using preorder hash
class Solution {
    string preorderHash(TreeNode* root) {
        if(!root) {
            return "#";
        }
        return to_string(root->val)
                + "," + preorderHash(root->left)
                + "," + preorderHash(root->right);
    }
    
    string checkSubtree(TreeNode* root, string const& signature, bool& isSubtree) {
        if(!root) {
            return "#";
        }
        if(isSubtree) {
            return "";
        }
        string preorder = to_string(root->val);
        preorder += "," + checkSubtree(root->left, signature, isSubtree);
        preorder += "," + checkSubtree(root->right, signature, isSubtree);
        if(preorder == signature) {
            isSubtree = true;
        }
        return preorder;
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string signature = preorderHash(t);
        bool isSubtree = false;
        checkSubtree(s, signature, isSubtree);
        return isSubtree;
    }
};