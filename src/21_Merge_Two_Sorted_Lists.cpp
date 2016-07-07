/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {  //Why it is slow?
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head, *node;
        head = new ListNode(0); // Dynamic allocated
        node = head;
        if (!l1 && !l2) {node->next = NULL;}
        while (l1 && l2 ) {
            if (l1->val <= l2 ->val) {
                node->next = l1;
                l1 = l1->next;
            }
            else {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        if (!l1) {node->next = l2;}
        if (!l2) {node->next = l1;}
        return head->next;
    }
};