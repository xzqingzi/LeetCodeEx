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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head, *node;
        head = new ListNode(0); // Dynamic allocated
        node = head;
        if (!l1 && !l2) {node->next = NULL;}
        while (l1 && l2 ) {
            if (l1->val <= l2 ->val) {
                node->next = l1;
                l1 = l1->next;
            }
            else {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        if (!l1) {node->next = l2;}
        if (!l2) {node->next = l1;}
        return head->next;
    }
};

 
// Other's Solution, use a reference of "head", remove several boundary condition. 
//Older usage, not very clear
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode** indirect = &head;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                *indirect = l1;
                l1 = l1->next;
            }
            else {
                *indirect = l2;
                l2 = l2->next;
            }
            indirect = &(*indirect)->next;
        }

        if (l1) {
            *indirect = l1;
        }
        if (l2) {
            *indirect = l2;
        }

        return head;
    }
};