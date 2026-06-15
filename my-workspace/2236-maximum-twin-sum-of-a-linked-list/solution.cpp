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
    int pairSum(ListNode* head) {
        vector<int> v1, v2;
        ListNode* temp = head;
        int n = 0;
        while(temp){
            n++;
            temp = temp->next;
        }
        temp = head;
        for(int i=0; i<n/2; i++){
            v1.push_back(temp->val);
            temp = temp->next;
        }
        reverse(v1.begin(), v1.end());
        int mx = INT_MIN;
        for(int i=0; i<n/2; i++){
            int v = temp->val;
            mx = max(mx ,v1[i] + v);
            temp = temp->next;
        }
        return mx;
    }
};
