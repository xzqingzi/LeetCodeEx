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
    ListNode* reverseBetween(ListNode* head, int m, int n) {  // given 1 ≤ m ≤ n ≤ length of list.
        if (m==n) return head;
        ListNode *p1, *p2, *newhead = new ListNode(0);
        newhead->next = head;
        p1 = head;
        p2 = newhead;
        int k = 1;
        while (k<n) {
            p1 = p1->next;
            if (k>n-m) {
                p2 = p2->next;
            }
            k++;
        }
        ListNode *prev, *tail, *curr;
        prev = p2->next;
        curr = prev->next;
        while (prev != p1) {
            tail = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tail;
        }
        p2->next->next = curr;
        p2->next = prev;
        
        return newhead->next;
    }
};