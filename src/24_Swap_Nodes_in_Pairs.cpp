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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head; 
        ListNode *p1, *p2, *temp, *newhead;
        p1 = head;
        newhead = p1->next;
        
        while(p1 && p1->next) {
            p2 = p1->next;
            temp = p2->next;
            p2->next = p1;
            if (temp && temp->next) p1->next = temp->next;
            else p1->next = temp;
            p1 = temp;
        }
        return newhead;
        
    }
};