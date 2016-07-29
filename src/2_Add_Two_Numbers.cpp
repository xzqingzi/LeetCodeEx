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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head, *p1;
        head = new ListNode(0);
        p1 = head;
        int sum, temp = 0;
        while (l1!=NULL || l2!=NULL || temp ) {
            sum = 0;
            sum = l1 ? sum + l1->val : sum;
            sum = l2 ? sum + l2->val : sum;
            sum += temp;
            
            p1->next = new ListNode(sum%10);
            temp = sum/10;
            
            p1 = p1->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return head->next;
    }
    
};


//The same as the above solution
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head, *p1;
        head = new ListNode(0); 
        p1 = head;
        int sum, temp = 0;
        while (l1 && l2) {
            sum = l1->val + l2->val + temp;
            p1->next = new ListNode(sum%10);
            temp = sum/10;
            p1 = p1->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            sum = l1->val+temp;
            p1->next = new ListNode(sum%10);
            temp = sum/10;
            p1 = p1->next;
            l1 = l1->next;
        }
        while (l2) {
            sum = l2->val+temp;
            p1->next = new ListNode(sum%10);
            temp = sum/10;
            p1 = p1->next;
            l2 = l2->next;
        }
        if (temp) {
            p1->next = new ListNode(temp);
        }
        return head->next;
        
    }
    
};