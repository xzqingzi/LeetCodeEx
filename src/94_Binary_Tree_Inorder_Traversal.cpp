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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        list(root, output);
        return output;
    }
    
    void list(TreeNode* root, vector<int>& output) { // Do not forget '&'
        if(!root) return;
        list(root->left, output);
        output.push_back(root->val);
        list(root->right, output);
    }
};