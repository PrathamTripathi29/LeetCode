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
    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX;
        int prevnode = -1;
        stack<TreeNode*> stack;
        while(root || !stack.empty()){
            while(root){
                stack.push(root);
                root = root->left;
            }
            root = stack.top(), stack.pop();
            if(prevnode >= 0){
                diff = min(diff, root->val - prevnode);
            }
            prevnode = root->val;
            root = root->right;
        }
        return diff;
    }
};
