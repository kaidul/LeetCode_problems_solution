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
    TreeNode* inorderSuccessor(TreeNode* node) {
        TreeNode* currNode = node;
        while(!currNode->left) {
            currNode = currNode->left;
        }
        return currNode;
    }
    
    TreeNode* inorderPredecessor(TreeNode* node) {
        TreeNode* currNode = node;
        while(!currNode->right) {
            currNode = currNode->right;
        }
        return currNode;
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) {
            return root;
        }
        if(key < root->val) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if(key > root->val) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        if(root->left == nullptr) {
            TreeNode* tmp = root->right;
            delete root;
            return root = tmp;
        }
        if(root->right == nullptr) {
            TreeNode* tmp = root->left;
            delete root;
            return root = tmp;
        }
#if 0
        // This works too
        TreeNode* minNode = inorderSuccessor(root->right);
        root->val = minNode->val;
        root->right = deleteNode(root->right, minNode->val);
#endif
        TreeNode* maxNode = inorderPredecessor(root->left);
        root->val = maxNode->val;
        root->left = deleteNode(root->left, maxNode->val);
        
        return root;
    }
};


// The idea is to serialize the preorder traversal sequence
// On deserialize, sort the preorder sequence and get inorder sequence, then construct BST using preorder and inorder traversal
// We are using BST property here, there is no need to track NULL node so its a compact encoding than above one
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
        int n = data.length();
        data.erase(n - 1, 1);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> preorder;
        int indx = 0;
        while(indx < data.length()) {
            int separator = data.find('#', indx);
            if(separator == string::npos) {
                separator = data.length() + 1;    
            }
            string key = data.substr(indx, separator - indx);
            cout << key << endl;
            preorder.push_back(atoi(key.c_str()));
            indx = separator + 1;
        }
        vector<int> inorder(preorder.begin(), preorder.end());
        if(preorder.empty()) return nullptr;
        sort(inorder.begin(), inorder.end());
        return treeBuilder(preorder, inorder, 0, preorder.size() - 1, 0);
    }
};