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
    int count = 0;
    int f(TreeNode* root){
        if(!root) return 0;
        int l = f(root->left);
        int r = f(root->right);
        if(root->val >= max(l, r)) count++;
        return max({root->val, l, r});
    }
    int countDominantNodes(TreeNode* root) {
        f(root);
        return count;
    }
};
