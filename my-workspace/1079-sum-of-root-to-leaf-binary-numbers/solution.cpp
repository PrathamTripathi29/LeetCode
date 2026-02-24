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
    int sumCalc(TreeNode* root, string curr){
        if(!root){
            return 0;
        }
        curr += root->val + '0';
        if(!root->left && !root->right){
            int num = stoi(curr, nullptr, 2);
            return num;
        }
        
        return sumCalc(root->left, curr) + sumCalc(root->right, curr);
    }
    int sumRootToLeaf(TreeNode* root) {
        string curr;
        return sumCalc(root, curr);
    }
};
