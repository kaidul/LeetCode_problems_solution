/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // Iteratively
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root) return root;
        unordered_map <TreeNode*, TreeNode*> parent;
        parent[root] = nullptr;
        while(root->left) {
            parent[root->left] = root;
            root = root->left;
        }
        TreeNode* newRoot = root;
        while(root) {
            root->left = root->right = nullptr;
            if(parent[root])
                root->left = parent[root]->right;
            root->right = parent[root];
            root = parent[root];
        }
        
        return newRoot;
    }
};

// Recursively
/*
class Solution {
    void upsideDownBinaryTreeRecur(TreeNode* parent, TreeNode* root, TreeNode*& newRoot) {
        if(!root) return;
        upsideDownBinaryTreeRecur(root, root->left, newRoot);
        if(!newRoot) {
            newRoot = root;
        }
        if(!parent) return;
        root->right = parent;
        root->left = parent->right;
        parent->left = parent->right = nullptr;
    }
    
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* newRoot = nullptr;
        upsideDownBinaryTreeRecur(nullptr, root, newRoot);
        return newRoot;
    }
};
*/