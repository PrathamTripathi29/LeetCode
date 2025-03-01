/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int tilt(TreeNode* root, int &tiltsum){
        if(!root){
            return 0;
        }
        int leftsum = tilt(root->left, tiltsum);
        int rightsum = tilt(root->right, tiltsum);
        tiltsum += abs(leftsum-rightsum);
        return leftsum + rightsum + root->val;
    }
    int findTilt(TreeNode* root) {
        int tiltsum = 0;
        tilt(root, tiltsum);
        return tiltsum;
    }
};
