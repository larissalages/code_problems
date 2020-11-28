class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
        {
            return head;
        }
        if(head->val==val)
        {
            while(head && head->val==val){
            head=head->next;
            }
        }
        ListNode* ptr=head;
        while(ptr && ptr->next!=NULL)
        {
            if(ptr->next->val==val)
            {
                ptr->next=ptr->next->next;
            }
            else
            ptr=ptr->next;
        }
        return head;
    }
