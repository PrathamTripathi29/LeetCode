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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp = head;
        while(temp){
            size++;
            temp = temp->next;
        }
        int todel = size-n+1;
        temp = head;
        if(size == 1){
        temp = NULL;
        return temp;
        }
        int i=1;
        if(todel == 1){
            ListNode* del = head;
            head = head->next;
            delete(del);
            return head;
        }
        while(i<todel-1){
            temp = temp->next;
            i++;
        }
        ListNode* del = temp->next;
        temp->next = temp->next->next;
        delete(del);
        return head;
    
    }
};
