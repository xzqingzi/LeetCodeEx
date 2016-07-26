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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        if (nums.size() == 1) return new TreeNode(nums[0]);
        int mid = nums.size()/2;
        TreeNode* root = new TreeNode(nums[mid]);
        vector<int> numsl(nums.begin(),nums.begin()+mid);
        vector<int> numsr(nums.begin()+mid+1,nums.end());
        
        root->left = sortedArrayToBST(numsl);
        root->right = sortedArrayToBST(numsr);
        return root;
        
    }
};