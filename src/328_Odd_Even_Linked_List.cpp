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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode* h2 = head->next;
        ListNode *p1= head, *p2 = h2;
        while (p2 && p2->next) {  // Ne careful about the statement, || does not work
            p1->next = p1->next->next;
            p2->next = p2->next->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = h2;
        return head;
    }
};