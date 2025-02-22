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
    TreeNode* constructtree(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend, map<int,int> &mp){
        if(prestart>preend || instart > inend){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[prestart]);
        int inroot = mp[root->val];
        int numsleft = inroot - instart;

        root->left = constructtree(preorder, prestart+1, prestart+numsleft, inorder, instart, inroot - 1, mp);
        root->right = constructtree(preorder, prestart+numsleft+1, preend, inorder, inroot+1, inend, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int prestart = 0, preend = preorder.size()-1;
        int instart = 0, inend = inorder.size()-1;
        map<int,int> mp;
        for(int i=instart; i<=inend;i++){
            mp[inorder[i]] = i;
        }

        return constructtree(preorder, prestart, preend, inorder, instart, inend, mp);
    }
};
