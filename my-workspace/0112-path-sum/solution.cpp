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
    bool pathsum(TreeNode* root, int sum, int targetSum){
        if(!root){
            return 0;
        }
        sum += root->val;
        if(!root->left && !root->right){
            return sum == targetSum;
        }
        else{
            return pathsum(root->left, sum, targetSum) || pathsum(root->right, sum, targetSum);
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return pathsum(root, sum, targetSum);
    }
};
