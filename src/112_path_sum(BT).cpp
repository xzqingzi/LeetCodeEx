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
    bool hasPathSum(TreeNode* root, int sum) {
       if (!root) {return 0;}
       int diff = sum - root->val;
       if ((!root->left ) && (!root->right)) { //check if it is leaf, otherwise is not the end
           return diff == 0;
       }
       return hasPathSum(root->left, diff) || hasPathSum(root ->right, diff);
    }
};