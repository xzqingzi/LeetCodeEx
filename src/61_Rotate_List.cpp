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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k==0 ) return head;
        ListNode *p1, *p2, *newhead;
        p1 = p2 = head;
        int i=0;
        while(i<k) {
            if (p1->next == NULL) {
                k = k % (i+1);
                if (k == 0) return head;
                p1 = head;
                i = 0;
            }
            p1 = p1->next;
            i++;
        }
        while(p1->next) {
            p1 = p1->next;
            p2 = p2->next;
        }
        newhead = p2->next;
        p2->next = NULL;
        p1->next = head;
        return newhead;
    }
};