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
    ListNode* reverse(ListNode* head){
        ListNode* temp=head,*prev=nullptr;
        while(temp!=nullptr){
            ListNode* newnode=temp->next;
            temp->next=prev;
            prev=temp;
            temp=newnode;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head,*slow=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* secondhead=reverse(slow->next);
        ListNode* first=head,*second=secondhead;
        bool result=true;
        while(second){
            if(first->val!=second->val){
                 result=false;
                  break;
            }    
                first=first->next;
                second=second->next;   
         }
         slow->next=reverse(secondhead);
         return result;
    }
};