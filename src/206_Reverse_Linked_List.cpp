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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        return Reverse(head,prev);
    }
        ListNode* Reverse(ListNode* head,ListNode* prev) {
        if(head == NULL){return prev;}
        ListNode* temp = head->next;
        head->next = prev;
        prev = head ;
        return Reverse(temp,prev);
    }
};