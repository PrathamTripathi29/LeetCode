/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, bool> vis;
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        q.push(target);
        int lvl = 0;
        while(!q.empty()){
            int size = q.size();
            if(lvl == k) break;
            lvl++;
            while(size--){
                TreeNode* node = q.front();
                vis[node] = true;
                q.pop();
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                }
                if(parent[node] && !vis[parent[node]]){
                    q.push(parent[node]);
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
