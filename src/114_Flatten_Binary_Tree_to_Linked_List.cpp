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
    void flatten(TreeNode* root) {
        if (!root) return;
        if (!root->left && !root->right ) return;
        
        if (root->left && root->right) {
            TreeNode* p1;
            p1 = root->left;
            while(p1->right) {
                p1 = p1->right;
            }
            p1->right = root->right;
        }
        
        if (root->left) {
            root->right = root->left;
            root->left = NULL;
        }
        
        flatten(root->right);
    }
};