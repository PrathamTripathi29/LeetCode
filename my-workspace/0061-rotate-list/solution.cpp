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
    ListNode* rotateRight(ListNode* head, int k) {
        int length = 0;
        ListNode* temp = head;
        ListNode* newhead = NULL;
        while(temp){
            length++;
            temp = temp->next;
        }
        if(!head){
            return head;
        }
        int rotate = k%length;
        int count = 0;
        while(count < rotate){
            temp = head;
            while(temp->next->next){
                temp = temp->next;
            }
            newhead = temp->next;
            temp->next->next = head;
            temp->next = NULL;
            head = newhead;
            count++;
        }
        return head;
    }
};
