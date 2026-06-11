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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return nullptr;
        if(!head->next->next){
            head->next = nullptr;
            return head;
        }
        int len = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            len++;
        }
        int del = (len+2)/2;
        int pos = 0;
        temp = head;
        while(pos < (del-2)){
            temp = temp->next;
            pos++;
        }
        temp->next = temp->next->next;
        return head;
    }
};
