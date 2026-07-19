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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* node = new TreeNode(val);
            return node;
        }
        TreeNode* ori = root;
        while(root){
            if(root->val > val){
                if(root->left) root = root->left;
                else{
                    TreeNode* node = new TreeNode(val);
                    root->left = node;
                    return ori;
                }
            } else {
                if(root->right) root = root->right;
                else {
                    TreeNode* node = new TreeNode(val);
                    root->right = node;
                    return ori;
                }
            }
        }
        return ori;
    }
};
