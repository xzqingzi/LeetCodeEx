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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> bfs;
        bfs.push(root);
        while(!bfs.empty()) {
            int n = bfs.size();
            vector<int> list;
            while(n>0) {
                TreeNode* p = bfs.front();
                bfs.pop();
                list.push_back(p->val);
                if (p->left) bfs.push(p->left);
                if (p->right) bfs.push(p->right);
                n--;
            }
            result.push_back(list);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};