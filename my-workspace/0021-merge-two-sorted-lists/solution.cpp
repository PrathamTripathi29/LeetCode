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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = NULL;
        ListNode* temp = NULL;
        while(list1 != NULL || list2 != NULL){
            ListNode* newnode = new ListNode;
            newnode->next = NULL;
            if(list1 == NULL){
                newnode->val = list2->val;
                list2 = list2->next;
                if(head == NULL){
                head = newnode;
            }
            else{
                temp->next = newnode;
            }
            temp = newnode;
                continue;
            }
            if(list2 == NULL){
                newnode->val = list1->val;
                list1 = list1->next;
                if(head == NULL){
                head = newnode;
            }
            else{
                temp->next = newnode;
            }
            temp = newnode;
                continue;
            }
            if(list1->val > list2->val){
                newnode->val = list2->val;
                list2 = list2->next;
            }
            else{
                newnode->val = list1->val;
                list1 = list1->next;
            }
            if(head == NULL){
                head = newnode;
            }
            else{
                temp->next = newnode;
            }
            temp = newnode;
        }
        return head;
    }
};
