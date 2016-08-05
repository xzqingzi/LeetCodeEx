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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode *p1, *p2;
        //Find the middle node (1-2-3-4-5-6)
        p1 =p2 = head;
        while(p2->next && p2->next->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        //Reverse the second half list (1-2-3-6-5-4)
        ListNode* mid = p1;
        p1 = p1->next;
        ListNode* pre = p1->next;
        ListNode* temp;
        while(pre) {
            temp = pre->next;
            pre->next = p1;
            p1 = pre;
            pre = temp;
        }
        mid->next->next = NULL;
        mid->next = p1;
        // Intersect (1-6-2-5-3-4)
        p2 = mid->next;
        p1 = head;
        ListNode *temp1, *temp2;
        while(p1 != mid) {
            temp1 = p1->next;
            p1->next = p2;
            temp2 = p2->next;
            p2->next = temp1;
            p1 = temp1;
            p2 = temp2;
        }
        p1->next = p2;
    }
};