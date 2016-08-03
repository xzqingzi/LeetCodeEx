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
    bool isValidBST(TreeNode* root) {
        return check(root, LONG_MIN, LONG_MAX);
    }
    bool check(TreeNode* node, long min, long max) {
        if (!node) return 1;
        if (node->val >= max || node->val <= min) return 0;
        return check(node->left, min, node->val) && check(node->right, node->val, max);
    }
};