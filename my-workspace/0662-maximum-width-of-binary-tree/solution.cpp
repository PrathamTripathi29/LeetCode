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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        long long width = 0;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            long long st = q.front().second;
            long long ed = q.back().second;
            width = max(width, ed-st+1);
            while(size--){
                auto [node, idx] = q.front();
                q.pop();
                idx = idx-st;
                if(node->left) q.push({node->left, 2*idx+1});
                if(node->right) q.push({node->right, 2*idx+2});
            }
        }
        return width;
    }
};
