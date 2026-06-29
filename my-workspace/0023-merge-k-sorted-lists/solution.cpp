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
    struct custom {
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, custom> pq;
        for(auto head : lists){
            if(head) pq.push(head);
        }
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        while(!pq.empty()){
            ListNode* top = pq.top();
            pq.pop();
            temp->next = top;
            temp = temp->next;
            if(top->next) pq.push(top->next);
        }
        return head->next;
    }
};
