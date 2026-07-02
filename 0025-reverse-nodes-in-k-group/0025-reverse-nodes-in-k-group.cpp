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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr)return head;
       ListNode* node=head;
       int count=0;
       while(node!=nullptr && count<k){
        node=node->next;
        count++;
       }
       if(count<k) return head;
       ListNode* prev=reverseKGroup(node,k);
       ListNode* cur=head;
       while(count-->0){
        ListNode* temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
       }
       return prev;
    }
};