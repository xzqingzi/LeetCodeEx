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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return head;
        ListNode *p1 = new ListNode(0), *p2 = new ListNode(0);
        ListNode *h1 = p1, *h2 = p2;
        ListNode *tail = head;
        while(tail) {
            if (tail->val < x)  {
                p1->next = tail;
                p1 = p1->next;
            }
            else {
                p2->next = tail;
                p2 = p2->next;
            }
            tail = tail->next;
        }
        p2->next = NULL;  //Important 
        p1->next = h2->next;
        delete h2;
        return h1->next;
    }
};