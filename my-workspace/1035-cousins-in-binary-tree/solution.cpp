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
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int levelsize = q.size();
            bool xfound = false, yfound = false;
            for(int i=0; i<levelsize; i++){
                TreeNode* current = q.front();
                q.pop();
                if(current->left && current->right){
                    if((current->left->val == x && current->right->val == y) || (current->left->val == y && current->right->val == x)){
                        return false;
                    }
                }
                if(current->left){
                    q.push(current->left);
                    if(current->left->val == x) xfound = true;
                    if(current->left->val == y) yfound = true;
                }
                if(current->right){
                    q.push(current->right);
                    if(current->right->val == x) xfound = true;
                    if(current->right->val == y) yfound = true;
                }

            }
            if(xfound && yfound) return true;
            if(xfound && yfound) return false;
        }
        return false;
    }

};
