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
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* temp = new ListNode(0);
        ListNode* curr = temp;
        while(left && right){
            if(left->val < right->val){
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        while(left){
            curr->next = left;
            left = left->next;
            curr = curr->next;
        }
        while(right){
            curr->next = right;
            right = right->next;
            curr = curr->next;
        }
        return temp->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        return merge(left, right);
    }
};
