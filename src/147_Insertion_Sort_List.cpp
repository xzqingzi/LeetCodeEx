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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* newhead = new ListNode(0);
        //newhead->next = head;
        // Do NOT link the newhead to head, make the tail to be NULL, so that we can know the end of the list
        ListNode *curr = head, *temp, *nextnode;
        while(curr) {
            nextnode = curr->next;
            temp = newhead;
            while(temp->next != NULL && temp->next->val < curr->val) {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
            curr = nextnode; //continue move to the next node
        }
        return newhead->next;
    }
};

//Faster solution 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newhead = new ListNode(0);
        newhead->next = head; //here the newnode is linked to the head, which means linked to the whole list
        ListNode *curr = head, *temp = newhead, *nextnode;
        while(curr) {
            if (curr->next && curr->val > curr->next->val) {
                nextnode = curr->next->next;
                temp = newhead;
                while(temp->next && temp->next->val < curr->next->val) {
                    temp = temp->next;
                }
                curr->next->next = temp->next;
                temp->next = curr->next;
                curr->next = nextnode;   
                //if the pos is switched, since the curr->next is changed, need to check again the value of curr->next, so no need to move to the next node, 
            }
            else {curr = curr->next; } //continue move to the next node
        }
        return newhead->next;
    }
};