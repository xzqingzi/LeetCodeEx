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
    bool hasCycle(ListNode *head) {
        if (!head) {return 0;}
        while(head->next && head->next->next) {
            if(head == head->next->next) {
                return 1;
            }
            head = head->next;
            head->next = head->next->next;
        }
        return 0;
        
    }
};