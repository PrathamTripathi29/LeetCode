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
    string smallestFromLeaf(TreeNode* root) {
        if(!root){
            return "";
        }
        string smallest = "~";
        stack<pair<TreeNode*, string>> s;
        s.push({root, ""});
        while(!s.empty()){
            TreeNode* curr = s.top().first;
            string path = s.top().second;
            s.pop();
            path = char(curr->val + 'a') + path;
            if(!curr->left && !curr->right){
                if(path < smallest){
                    smallest = path;
                }
            }
            if(curr->right){
                s.push({curr->right, path});
            }
            if(curr->left){
                s.push({curr->left, path});
            }
        }
        return smallest;
    }
};
