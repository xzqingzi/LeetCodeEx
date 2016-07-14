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
    bool isSymmetric(TreeNode* root) {
        if(!root) return 1;
        return isSame(root->left, root->right);
    }
    
    bool isSame(TreeNode* p, TreeNode* q) {
        if( !p && !q) return 1;
        if( p && q && p->val == q->val) {
        return isSame(p->left, q->right) &&isSame(p->right, q->left);
        }
        return 0;
    }
};