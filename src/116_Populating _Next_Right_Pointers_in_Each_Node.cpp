/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode *p = root, *curr = NULL;
        while (p->left) {
            curr=p;
            while(curr->next) {
                curr->left->next = curr->right;
                curr->right->next = curr->next->left;
                curr = curr->next;
                }
                curr->left->next = curr->right;
                p = p->left;
        }
        return;
    }
};