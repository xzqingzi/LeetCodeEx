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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        if ((!root->left) && (!root->right)) return root;
        TreeNode* temp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = temp;
        return root;
    }
};