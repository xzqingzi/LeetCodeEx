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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> list;
        getsum(result, list, root, sum);
        return result;
    }
    
    void getsum(vector<vector<int>>& result, vector<int>& list, TreeNode* root, int sum) {
        if (!root) return;
        list.push_back(root->val);
        if (!root->left && !root->right && sum == root->val) {
            result.push_back(list);
        }
        getsum(result, list, root->left, sum - root->val);
        getsum(result, list, root->right, sum - root->val);
        list.pop_back(); // For the last node, both obove get sum directly return, this step remove the last push. 
    }
};