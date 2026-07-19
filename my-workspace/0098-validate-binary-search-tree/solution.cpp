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
    bool check(TreeNode* root, long long l, long long h){
        if(!root) return true;
        if(root->val >= h || root->val <= l) return false;
        return check(root->left, l, root->val) && check(root->right, root->val, h);
    }
    bool isValidBST(TreeNode* root) {
        long long h = LLONG_MAX;
        long long l = LLONG_MIN;
        return check(root, l, h);
    }
};
