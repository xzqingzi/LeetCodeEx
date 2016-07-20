/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //recursion
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> list;
        TreeNode* p = root;
        prelist(p, list);
        return list;
    }
    
    void prelist(TreeNode* p, vector<int>& list) {
        if(!p) return;
        list.push_back(p->val);
        prelist(p->left, list);
        prelist(p->right, list);
    }
};


//iteration
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> output;
        TreeNode* p = root;
        stack<TreeNode*> nodelist;
        while(p || !nodelist.empty()) {
            if (p) {
                nodelist.push(p);
                output.push_back(p->val);
                p = p->left;
            }
            else {
                p = nodelist.top();
                nodelist.pop();
                p = p->right;
            }
        }
        return output;
        
    }
};