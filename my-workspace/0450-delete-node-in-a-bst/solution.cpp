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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        TreeNode* ori = root;
        TreeNode* parent = nullptr;
        int child;
        while(root){
            if(root->val == key){
                if(!parent){
                    if(!root->left) return root->right;
                    if(!root->right) return root->left;
                    TreeNode* newRoot = root->right;
                    TreeNode* leftSubTree = root->left;
                    root = root->right;
                    while(root->left){
                        root = root->left;
                    }
                    root->left = leftSubTree;
                    return newRoot;
                }
                if(child == 0){
                    if(root->right){
                        parent->left = root->right;
                        TreeNode* leftSubTree = root->left;
                        if(leftSubTree){
                        root = root->right;
                        while(root->left){
                            root = root->left;
                        }
                        root->left = leftSubTree;
                        }
                    } else if(root->left){
                        parent->left = root->left;
                    } else {
                        parent->left = nullptr;
                    }
                    return ori;
                }
                if(child == 1){
                    if(root->right){
                        parent->right = root->right;
                        TreeNode* leftSubTree = root->left;
                        if(leftSubTree){
                        root = root->right;
                        while(root->left){
                            root = root->left;
                        }
                        root->left = leftSubTree;
                        }
                    } else if(root->left){
                        parent->right = root->left;
                    } else {
                        parent->right = nullptr;
                    }
                    return ori;
                }
            }
            if(root->val > key){
                parent = root;
                root = root->left;
                child = 0;
            } else {
                parent = root;
                root = root->right;
                child = 1;
            }
        }
        return ori;
    }
};
