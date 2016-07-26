/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* findMid(ListNode* head) {
        ListNode *p1 = head, *p2 = head->next;
        while (p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return p1;
    }
    ListNode* merge(ListNode* h1, ListNode* h2) {
        ListNode *head, *p;
        head = new ListNode(0);
        p = head;
        while(h1 && h2) {
            if (h1->val < h2->val) {
                p->next = h1;
                h1 = h1->next;
            }
            else {
                p->next = h2;
                h2 = h2->next;
            }
            p = p->next;
        }
        if (h1) p->next = h1;
        if (h2) p->next = h2;
        return head->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode* h2 = findMid(head);
        
        ListNode* headr = sortList(h2->next);
        h2->next = NULL;
        ListNode* headl = sortList(head);
        
        return merge(headl, headr);
    }
};