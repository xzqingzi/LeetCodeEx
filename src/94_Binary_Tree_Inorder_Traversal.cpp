/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //Using recursion
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

// Using iteration
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> list; //Save the whole node pointer in the stack
        vector<int> output;
        TreeNode* node = root;
        while(node || !list.empty()) { 
            if (node) {
                list.push(node);
                node = node->left;
            }
            else {
                node = list.top();
                output.push_back(node->val);
                node = node->right;
                list.pop();
            }
        }
        return output;
    }
};