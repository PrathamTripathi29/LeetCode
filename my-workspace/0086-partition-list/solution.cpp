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
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1 = NULL;
        ListNode* temp1 = NULL;
        ListNode* head2 = NULL;
        ListNode* temp2 = NULL;
        ListNode* temp = head;
        if(!head){
            return head;
        }
        while(temp){
            if(temp->val < x){
                if(!head1){
                    head1 = temp;
                    temp1 = head1;
                }
                else{
                    temp1->next = temp;
                    temp1 = temp1->next;
                }
            }
            else{
                if(!head2){
                    head2 = temp;
                    temp2 = head2;
                }
                else{
                    temp2->next = temp;
                    temp2 = temp2->next;
                }
            }
            temp = temp->next;
        }
        if(temp2){
            temp2->next = NULL;
        }
        if(!head1){
            return head2;
        }
        temp1->next = head2;
        return head1;
    }
};
