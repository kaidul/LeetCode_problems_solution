class BSTIterator {
public:
    vector <TreeNode*> nodes;
    int iter = 0;
    BSTIterator(TreeNode *root) {
        BSTIteratorUtils(root);
    }

    void BSTIteratorUtils(TreeNode *node) {
        if(!node) return;
        BSTIteratorUtils(node->left);
        nodes.push_back(node);
        BSTIteratorUtils(node->right);
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