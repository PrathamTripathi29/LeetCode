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
    int lheight(TreeNode* root){
        if(!root) return 0;
        return lheight(root->left) + 1;
    }
    int rheight(TreeNode* root){
        if(!root) return 0;
        return rheight(root->right) + 1;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = lheight(root);
        int rh = rheight(root);
        if(lh == rh) return (1<<lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
