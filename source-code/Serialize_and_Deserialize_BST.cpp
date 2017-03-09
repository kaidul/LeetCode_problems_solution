/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Any serialize-deserialize technique working for BT will work for BST because BST is a BT but may not the other way around
class Codec {
    void preorder(TreeNode* root, string& data) {
        if(!root) return;
        data.append(to_string(root->val) + '#');
        preorder(root->left, data);
        preorder(root->right, data);
    }
    
    TreeNode *treeBuilder(vector<int> &preorder, vector<int> &inorder, int start, int end, int indx) {
        if(start > end) return nullptr;
        
        TreeNode *root = new TreeNode(preorder[indx]);
        int rootPosition;    
        for(int i = start; i <= end; ++i) {
            if(inorder[i] == root->val) {
                rootPosition = i;
                break;
            }
        }
        root->left = treeBuilder(preorder, inorder, start, rootPosition - 1, indx + 1);
        root->right = treeBuilder(preorder, inorder, rootPosition + 1, end, indx + 1 + rootPosition - start);
        return root;
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        if(!root) return data;
        preorder(root, data);
        // int n = data.length();
        // data.erase(n - 1, 1);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> preorder;
        int indx = 0;
        while(indx < data.length()) {
            int separator = data.find('#', indx);
            // if(separator == string::npos) {
            //     separator = data.length() + 1;    
            // }
            string key = data.substr(indx, separator - indx);
            preorder.push_back(atoi(key.c_str()));
            indx = separator + 1;
        }
        vector<int> inorder(preorder.begin(), preorder.end());
        if(preorder.empty()) return nullptr;
        sort(inorder.begin(), inorder.end());
        return treeBuilder(preorder, inorder, 0, preorder.size() - 1, 0);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));