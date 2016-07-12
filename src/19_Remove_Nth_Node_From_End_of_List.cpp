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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1, *p2;
        p1 = head;
        p2->next = head;
        head = p2;  //P2 here is NULL
        int k=1;
        while(p1) {
            if (p1->next == NULL) {
                    p2->next = p2->next->next;
                    break;
                }
            if(k >= n) {
                p2 = p2->next;
            }
            p1 = p1->next;
            k ++;
        }
        return head->next;      
    }
};