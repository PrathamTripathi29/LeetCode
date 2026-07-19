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
    int val;
    void inorder(TreeNode* root, int& curr, int k){
        if(!root) return;
        inorder(root->left, curr, k);
        if(curr==k){
            val = root->val;
        }
        curr++;
        inorder(root->right, curr, k);

    }
    int kthSmallest(TreeNode* root, int k) {
        int curr = 1;
        inorder(root, curr, k);
        return val;
    }
};
