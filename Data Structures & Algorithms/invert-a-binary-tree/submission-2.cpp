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

    void invertT(TreeNode* node){
        if(!node) return;
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        swap(left , right);
    }

    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;

        swap(root->right , root->left);

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
