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
    vector<int> rightSideView(TreeNode* root) {
        //if (root == NULL) return ;
        queue<TreeNode*> myque; 
        if (root) myque.push(root); 
        vector<int> result;
        while(!myque.empty()) {
            int n = myque.size();
            result.push_back(myque.back()->val);
            for (int i=0; i<n; i++) {
                TreeNode* temp = myque.front();
                if (temp->left) myque.push(temp->left);
                if (temp->right) myque.push(temp->right);
                myque.pop();
            }
        }
        return result;
    }
};


// Other's smart solution   
public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        helper(res, root, 0);
        return res;
    } 

public void helper(List<Integer> res, TreeNode root, int level) {
        if(root == null) return;
        if(res.size() == level) 
            res.add(level, root.val);
        helper(res, root.right, level + 1);
        helper(res, root.left, level + 1);
    }