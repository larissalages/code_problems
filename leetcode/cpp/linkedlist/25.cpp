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
        auto *initial=head;
        ListNode *prevTail=NULL;
        while(head){
            ListNode *curr=NULL,*tail=NULL;
            int count=k;
            while(count){
                if(!head) return initial;
                auto *x=new ListNode(head->val);
                x->next=curr;
                curr=x;
                head=head->next;
                if(!tail) tail=curr;
                count--;
            }
            if(!prevTail) initial=curr;
            else prevTail->next=curr;
            prevTail=tail;
            tail->next=head;
        }
       return initial;
    }
};