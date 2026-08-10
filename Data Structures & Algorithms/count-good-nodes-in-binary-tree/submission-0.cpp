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
    int dfs(TreeNode* node , int maxi){
        //base case
        if(!node) return 0;

        int count = 0;

        if(node->val >= maxi){
            count = 1;
        }
        maxi = max(node->val , maxi);
        // else //count remain same

        //left , right traversal
        int left = dfs(node ->left , maxi); //count of left
        int right = dfs(node->right , maxi); //count of right

        //return the total count
        return count + left + right;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root , INT_MIN);
    }
};
