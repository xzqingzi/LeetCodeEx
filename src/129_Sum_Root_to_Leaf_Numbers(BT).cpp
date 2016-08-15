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
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
    int helper(TreeNode* p, int num) {
        if (p == NULL) return 0;
        num = num*10 + p->val;
        if (p->left == NULL && p->right == NULL) return num;
        return helper(p->left, num) + helper(p->right, num);  
    }
};