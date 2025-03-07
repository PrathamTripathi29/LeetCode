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
    void helper(TreeNode* root, int &sum, string num){
        if(!root){
            return;
        }
        num += root->val + '0';
        if(!root->left && !root->right){
            sum += stoi(num);
            return;
        }
        helper(root->left, sum, num);
        helper(root->right, sum, num);
        return;
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        string num = "";
        helper(root, sum, num);
        return sum;
    }
};
