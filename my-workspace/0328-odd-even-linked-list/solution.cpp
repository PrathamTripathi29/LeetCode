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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* evenHead = nullptr;
        ListNode* oddHead = nullptr;
        ListNode* newHead;
        ListNode* originalEvenHead;
        int pos = 1;
        while(head){
            if(pos%2){
                if(!oddHead){
                    oddHead = head;
                    newHead = head;
                } else {
                    oddHead->next = head;
                    oddHead = head;
                }
            } else {
                if(!evenHead){
                    evenHead = head;
                    originalEvenHead = head;
                } else {
                    evenHead->next = head;
                    evenHead = head;
                }
            }
            head = head->next;
            pos++;
        }
        if(oddHead) oddHead->next = nullptr;
        if(evenHead) evenHead->next = nullptr;
        if(oddHead) oddHead->next = originalEvenHead;
        return newHead;
    }
};
