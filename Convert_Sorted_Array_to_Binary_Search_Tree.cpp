class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int> &arr, int start, int end) {
        if (start > end) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode *node = new TreeNode(arr[mid]);
        node->left = sortedArrayToBST(arr, start, mid - 1);
        node->right = sortedArrayToBST(arr, mid + 1, end);
        return node;
    }

    TreeNode *sortedArrayToBST(vector<int> &num) {
        int n = num.size();
        return sortedArrayToBST(num, 0, n - 1);
    }
};