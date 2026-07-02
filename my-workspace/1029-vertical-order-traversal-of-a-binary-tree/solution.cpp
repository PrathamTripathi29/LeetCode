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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // vertical -> (level -> [nodes])
        map<int, map<int, multiset<int>>> mp;
        vector<vector<int>> ans;

        //node, vertical, level
        queue<tuple<TreeNode*, int, int>> q;

        q.push({root, 0, 0});
        while(!q.empty()){
            auto [node, v, l] = q.front();
            q.pop();
            mp[v][l].insert(node->val);
            if(node->left) q.push({node->left, v-1, l+1});
            if(node->right) q.push({node->right, v+1, l+1});
        }
        for(auto v : mp){
            vector<int> temp;
            for(auto l : v.second){
                temp.insert(temp.end(), mp[v.first][l.first].begin(), mp[v.first][l.first].end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
