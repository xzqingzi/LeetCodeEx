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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode *p1, *p2;
        p1 = p2 = head;
        while(p2) {
            if (p1->val != p2->val) {
                p1->next = p2;
                p1 = p1->next;
            }
            p2 = p2->next;
        }
        p1->next = NULL;
        return head;
    }
};