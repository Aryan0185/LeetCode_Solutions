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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      if(head==nullptr) return head;
      ListNode* temp=head;
      int cnt=0;
      while(temp!=nullptr){
        temp=temp->next;
        cnt++;
      }
      cnt=cnt-n;
      if(cnt==0){
        ListNode* newnode=head->next;
        delete head;
        return newnode;
      }
      temp=head;
      int cntnum=0;
       ListNode* prev=nullptr;
      while(temp!=nullptr){
        if(cntnum==cnt){
           prev->next=temp->next;
           delete temp;
           break;
        }
        prev=temp;
        temp=temp->next;
        cntnum++;
      }
      return head;
    }
};