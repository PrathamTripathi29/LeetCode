/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* temp = NULL;
        int c = 0;
        while(l1 != NULL && l2 != NULL){
            ListNode* newnode = new ListNode;
            newnode->val = (l1->val + l2->val + c)%10;
            newnode->next = NULL;
            c = (l1->val + l2->val + c)/10;
            if(head == NULL){
                head = newnode;
            }
            else{
                temp->next = newnode;
            }
            temp = newnode;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
            ListNode* newnode = new ListNode;
            newnode->val = (l1->val + c)%10;
            newnode->next = NULL;
            c = (l1->val + c)/10;
            if(head == NULL){
                head = newnode;
            }
            else{
                temp->next = newnode;
            }
            temp = newnode;
            l1 = l1->next;
        }
        while(l2 != NULL){
            ListNode* newnode = new ListNode;
            newnode->val = (l2->val + c)%10;
            newnode->next = NULL;
            c = (l2->val + c)/10;
            if(head == NULL){
                head = newnode;
            }
            else{
                temp->next = newnode;
            }
            temp = newnode;
            l2 = l2->next;
        }
        if(c != 0){
            ListNode* newnode = new ListNode;
            newnode->val = c;
            newnode->next = NULL;
            if(head == NULL){
                head = newnode;
            }
            else{
                temp->next = newnode;
                temp = temp->next;
            }
            temp = head;
        }
        return head;
    }
};
