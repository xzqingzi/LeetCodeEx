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
    int kthSmallest(TreeNode* root, int k) {
        int count =0;
        stack<TreeNode*> list;
        TreeNode* p = root;
        while (p||count<=k) {
            if(p) {
                list.push(p);
                p = p->left;
            }
            else {
                p = list.top();
                count++;
                if (count == k) {break;}
                list.pop();
                p = p->right;
            }
        }
        return p->val;       
    }
};

//Go through all the nodes, has runtime O(n)