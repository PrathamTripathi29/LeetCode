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
    void helper(TreeNode* root, int mx, int &count){
        if(!root){
            return;
        }
        if(root->val >= mx){
            count++;
            mx = root->val;
        }
        helper(root->left, mx, count);
        helper(root->right, mx, count);
        return;
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        helper(root, root->val, count);
        return count;
    }
};
