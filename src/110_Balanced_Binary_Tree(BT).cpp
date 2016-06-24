/**
 * Definition for a binary tree node.
 * struct TreeNode {     //declare a structure type called TreeNode
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int depth(TreeNode* Node){
        if (!Node) { return 0; }  // (!x) is equal to (x==0),means x is false
        return max(depth(Node -> left), depth(Node -> right)) +1;
    }
    bool isBalanced(TreeNode* root) {
         if(!root) {return 1;}
         int diff = abs(depth(root -> left)-depth(root ->right));
         if (diff >1){return 0;}
         return isBalanced(root -> left) && isBalanced(root -> right);
    }
};