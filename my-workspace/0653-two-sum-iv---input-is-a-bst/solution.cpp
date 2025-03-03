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
    void inorder(TreeNode* root, vector<int> &intrav){
        if(root){
            inorder(root->left, intrav);
            intrav.push_back(root->val);
            inorder(root->right, intrav);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> intrav;
        inorder(root, intrav);
        int i = 0;
        int j = intrav.size()-1;
        while(i<j){
            if(intrav[i] + intrav[j] == k){
                return true;
            }
            else if(intrav[i] + intrav[j] > k){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};
