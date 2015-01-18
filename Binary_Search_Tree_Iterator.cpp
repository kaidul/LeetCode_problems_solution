class BSTIterator {
public:
    vector <TreeNode*> nodes;
    int iter = 0;
    BSTIterator(TreeNode *root) {
        BSTIteratorUtils(root, root);
    }

    void BSTIteratorUtils(TreeNode *node, TreeNode *root) {
        if(!node) return;
        BSTIteratorUtils(node->left, root);
        nodes.push_back(node);
        BSTIteratorUtils(node->right, root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return iter < nodes.size();
    }

    /** @return the next smallest number */
    int next() {
        return nodes[iter++]->val;
    }
};