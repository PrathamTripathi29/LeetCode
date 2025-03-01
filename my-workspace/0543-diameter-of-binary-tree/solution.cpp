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
    int maxheight(TreeNode* root, int &diameter){
        if(!root){
            return 0;
        }
        else{
            int ld = maxheight(root->left, diameter);
            int rd = maxheight(root->right, diameter);
            diameter = max(diameter, ld + rd);
            return max(ld,rd) + 1;;
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        maxheight(root, diameter);
        return diameter;
    }
};
