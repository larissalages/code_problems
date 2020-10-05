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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
       if(!head || !head->next || m==n) return head;
       auto *initial=head;
       m-=1;
       n-=m;
       ListNode *mpos=NULL;
       while(m){
           mpos=head;
           head=head->next;
           m--;
       }
       ListNode *list=NULL,*listhead=NULL;
       while(n){
           auto *x=new ListNode(head->val);
           if(!list) listhead=x;
           x->next=list;
           list=x;
           head=head->next;
           n--;
       }
       if(!mpos) initial=list;
       else mpos->next=list;
       listhead->next=head;
       return initial;
    }
};