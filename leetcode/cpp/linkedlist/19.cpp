class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slowptr=head,*fastptr=head,*temp;
        for(int index=0;index<n;index++){
            fastptr=fastptr->next;
        }
        if(fastptr==NULL) return head->next;
        while(fastptr->next!=NULL){
            slowptr=slowptr->next;
            fastptr=fastptr->next;
        }
        temp=slowptr->next;
        slowptr->next=slowptr->next->next;
        delete temp;
        return head;
    }
};