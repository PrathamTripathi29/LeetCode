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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root){
            return -1;
        }
        queue<TreeNode*> q;
        q.push(root);
        int minimum = root->val;
        long int secmin = LONG_MAX;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->val > minimum && curr->val < secmin){
                    secmin = curr->val;
                }
                if(curr->left && curr->right){
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
        }
        if(secmin == LONG_MAX){
            return -1;
        }
        return secmin;
    }
};
