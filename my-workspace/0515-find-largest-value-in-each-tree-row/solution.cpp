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
    vector<int> largestValues(TreeNode* root) {
        vector<int> rowmax;
        if(!root){
            return rowmax;
        }
        queue<TreeNode*> q;
        q.push(root);
        rowmax.push_back(root->val);
        while(!q.empty()){
            int ls = q.size();
            int macel = INT_MIN;
            for(int i=0; i<ls; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                    macel = max(macel, curr->left->val);
                }
                if(curr->right){
                    q.push(curr->right);
                    macel = max(macel, curr->right->val);
                }
            }
                rowmax.push_back(macel);
        }
        rowmax.pop_back();
        return rowmax;
    }
};
