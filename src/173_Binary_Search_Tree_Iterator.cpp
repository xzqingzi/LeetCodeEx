/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> list; //can be used in all public functions, keep changing through different func
public:
    BSTIterator(TreeNode *root) {
        findleft(root); //no need to input list again in func, already existed in private
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (list.empty()) return 0;
        return 1;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* p = list.top();
        list.pop();
        if (p->right) {
            findleft(p->right);
        }
        return p->val;
        
    }
    
    void findleft(TreeNode* root) {
            TreeNode* p = root;
            while(p) {
                list.push(p);
                p = p->left;
            }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */