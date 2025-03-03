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
    int minheight(TreeNode* root){
        if(!root){
            return 0;
        }
        if(root->left && !root->right){
            return minheight(root->left) + 1;
        }
        if(root->right && !root->left){
            return minheight(root->right) + 1;
        }
        int l = minheight(root->left);
        int r = minheight(root->right);
        return 1 + min(l,r);
    }
    int minDepth(TreeNode* root) {
        return minheight(root);
    }
};
