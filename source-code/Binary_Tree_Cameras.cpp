/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Greedy solution
class Solution {
    const int HAS_NO_CAMERA_AND_NOT_MONITORED = 0;
    const int HAS_NO_CAMERA_BUT_MONITORED = 1;
    const int HAS_CAMERA = 2;
    
    int minCameraCover(TreeNode* root, int& totalCameras) {
        if (!root) {
            return HAS_NO_CAMERA_BUT_MONITORED;
        }
        int left = minCameraCover(root->left, totalCameras);
        int right = minCameraCover(root->right, totalCameras);
        
        if (left == HAS_NO_CAMERA_AND_NOT_MONITORED or 
            right == HAS_NO_CAMERA_AND_NOT_MONITORED) {
            
            totalCameras++;
            return HAS_CAMERA;
        }
        else if (left == HAS_CAMERA or 
                 right == HAS_CAMERA) {
            
            return HAS_NO_CAMERA_BUT_MONITORED;
        }
        
        return HAS_NO_CAMERA_AND_NOT_MONITORED;
    }
public:
    int minCameraCover(TreeNode* root) {
        int totalCameras = 0;
        if (minCameraCover(root, totalCameras) == HAS_NO_CAMERA_AND_NOT_MONITORED) {
            totalCameras++;
        }
        return totalCameras;    
    }
};

// DP solution
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
    int minCameraCover(TreeNode* root, bool hasCamera, bool isMonitored, unordered_map<TreeNode*, unordered_map<bool, unordered_map<bool, int>>>& dp) {
        if (!root) {
          return 0;
        }
        if (dp[root][hasCamera][isMonitored]) {
          return dp[root][hasCamera][isMonitored];
        }
        if (hasCamera) {
          return dp[root][hasCamera][isMonitored] = 1 
              + minCameraCover(root->left, false, true, dp) 
              + minCameraCover(root->right, false, true, dp);    
        } 
        if (isMonitored) {
        int noCamera = minCameraCover(root->left, false, false, dp) 
                     + minCameraCover(root->right, false, false, dp);
        int withCamera = 1 
            + minCameraCover(root->left, false, true, dp) 
            + minCameraCover(root->right, false, true, dp);

        return dp[root][hasCamera][isMonitored] = min(noCamera, withCamera);
        }

        // no camera, not monitored
        int withCamera = 1 
          + minCameraCover(root->left, false, true, dp) 
          + minCameraCover(root->right, false, true, dp);

        int leftCamera = root->left ? minCameraCover(root->left, true, false, dp) 
          + minCameraCover(root->right, false, false, dp) : INT_MAX;
        int rightCamera = root->right ? minCameraCover(root->left, false, false, dp) 
          + minCameraCover(root->right, true, false, dp) : INT_MAX;

        return dp[root][hasCamera][isMonitored] = min({withCamera, leftCamera, rightCamera});
    }
public:
    int minCameraCover(TreeNode* root) {
        unordered_map<TreeNode*, unordered_map<bool, unordered_map<bool, int>>> dp;
        return min(minCameraCover(root, true, false, dp), minCameraCover(root, false, false, dp));
    }
};