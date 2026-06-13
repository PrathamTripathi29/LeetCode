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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(1){
            if(tempA == tempB) return tempA;
            if(!tempA) tempA = headB;
            else tempA = tempA->next;
            if(!tempB) tempB = headA;
            else tempB = tempB->next;
        }
        return nullptr;
    }
};
