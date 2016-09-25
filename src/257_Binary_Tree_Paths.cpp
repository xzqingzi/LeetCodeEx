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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string list = "";
        if (root) helper(result, list, root); 
        return result;
    }
    
    void helper(vector<string>& result, string list, TreeNode* p) {
         // Can not use string& list
        //the same string should not be used in each iteration (number will be superposed, it should be copied each time the function is called) 
        if (!p->right && !p->left) {
            result.push_back(list + to_string(p->val));
            return; 
        }
        //list += to_string(p->val) + "->";
        if (p->left) helper(result, list+to_string(p->val)+"->", p->left); 
        if (p->right) helper(result, list+to_string(p->val)+"->", p->right); 
    }
};