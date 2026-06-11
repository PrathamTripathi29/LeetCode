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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next){
            return true;
        }
        int len = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            len++;
        }
        int n = (len+1)/2;
        stack<int> s;
        temp = head;
        for(int i=0; i<n; i++){
            s.push(temp->val);
            temp = temp->next;
        }
        if(len&1){
            s.pop();
        }
        while(temp){
            if(temp->val != s.top()) return false;
            s.pop();
            temp = temp->next;
        }
        if(s.empty()) return true;
        return false;
    }
};
