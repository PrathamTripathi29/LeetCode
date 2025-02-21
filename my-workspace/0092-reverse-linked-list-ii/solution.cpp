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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int size;
        size = right - left + 1;
        int arr[size];
        int tr = 1;
        int index = 0;
        ListNode* temp = head;
        while(tr < left){
            temp = temp->next;
            tr++;
        }
        while(tr <= right){
            arr[index] = temp->val;
            temp = temp->next;
            tr++;
            index++;
        }
        temp = head;
        index = 0;
        tr = 1;
        while(tr < left){
            temp = temp->next;
            tr++;
        }
        while(tr <= right){
            temp->val = arr[size-1-index];
            temp = temp->next;
            tr++;
            index++;
        }
        return head;
    }
};
