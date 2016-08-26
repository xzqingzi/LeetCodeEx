/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        return createBST(head, NULL);
    }
private:    
    TreeNode* createBST(ListNode* head, ListNode* tail ) {
        TreeNode* root;
        if (head == tail) return NULL;
        if (head->next == tail)  return new TreeNode(head->val);

        ListNode* temp = FindMid(head, tail);
        
        root = new TreeNode(temp->val);
        root->left = createBST(head, temp);
        root->right = createBST(temp->next, tail);
        return root;
    }
    
    ListNode* FindMid(ListNode* head, ListNode* tail) {
        ListNode *p1, *p2;
        p1 = p2 = head;
        while(p1->next != tail && p1->next->next != tail) {
            p2 = p2->next;
            p1 = p1->next->next;
        }
        return p2;
    }
};