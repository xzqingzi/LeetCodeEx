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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return 1; //When both trees go to the end, it means they are the same. 
        if (p == NULL && q != NULL) return 0;
        if (p != NULL && q == NULL) return 0;
        if (p->val != q->val) return 0;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};