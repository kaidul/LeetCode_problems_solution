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
    int findFrequentTreeSum(TreeNode* root, unordered_map<int, int>& freq) {
        if(!root) {
            return 0;
        }
        int sum = 0;
        sum += root->val;
        sum += findFrequentTreeSum(root->left, freq);
        sum += findFrequentTreeSum(root->right, freq);
        
        freq[sum]++;
        return sum;
    }
    
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> result;
        unordered_map<int, int> freq;
        findFrequentTreeSum(root, freq);
        int maxFreq = 0;
        for(auto it = freq.begin(); it != freq.end(); ++it) {
            maxFreq = max(maxFreq, it->second);
        }
        for(auto it = freq.begin(); it != freq.end(); ++it) {
            if(it->second == maxFreq) {
                result.push_back(it->first);
            }
        }
        
        return result;
    }
};