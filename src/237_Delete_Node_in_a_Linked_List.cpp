/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {  // Void ?  No need to return a value, or takes no actual parameters when called
        if (!node) return;
        ListNode* temp = node->next;
        node->val = temp->val;
        node->next = temp ->next;
        delete temp; //What if not delete
        return;
    }
};