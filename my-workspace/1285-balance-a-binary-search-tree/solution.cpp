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
    void dfs(TreeNode* root, vector<TreeNode*>& nodes){
        if(!root) return;
        
        if(root->left) dfs(root->left, nodes);
        nodes.push_back(root);
        if(root->right) dfs(root->right, nodes);
    }
    TreeNode* buildTree(int l, int r, vector<TreeNode*>& nodes){
        if(l>r) return NULL;
        int mid = l + (r-l)/2;
        TreeNode* left = buildTree(l, mid-1, nodes);
        TreeNode* right = buildTree(mid+1, r, nodes);
        nodes[mid]->left = left;
        nodes[mid]->right = right;
        return nodes[mid];
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        dfs(root, nodes);
        int n = nodes.size();
        return buildTree(0, n-1, nodes);
    }
};
