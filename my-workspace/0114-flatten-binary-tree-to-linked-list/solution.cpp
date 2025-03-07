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
    void preorder(TreeNode* root, vector<int> &preord){
        if(root){
            preord.push_back(root->val);
            preorder(root->left, preord);
            preorder(root->right, preord);
        }
    }
    TreeNode* helper(TreeNode* root, vector<int> &preord){
        TreeNode* ori = root;
        for(int i=0; i<preord.size()-1; i++){
            root->val = preord[i];
            root->left = NULL;
            root->right = new TreeNode;
            root = root->right;
        }
        root->val = preord[preord.size()-1];
        root->left = root->right = NULL;
        return ori;
    }
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        vector<int> preord;
        preorder(root, preord);
        root = helper(root, preord);
        return;
    }
};
