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
    int bitodec(vector<int> num){
        int dec = 0;
        int n = num.size();
        for(int i=0; i<num.size(); i++){
            dec += num[i] * (1 << (n-1-i));
        }
        return dec;
    }
    int sum(TreeNode* root, vector<int> num){
        if(!root){
            return 0;
        }
        num.push_back(root->val);
        if(!root->left && !root->right){
            return bitodec(num);
        }
        return sum(root->left, num) + sum(root->right, num);
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<int> num;
        return sum(root, num);
    }
};
