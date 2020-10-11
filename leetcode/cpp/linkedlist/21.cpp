// Merged Two Sorted Linked Lists

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL || l2==NULL)
            return l1==NULL?l2:l1;
        ListNode* head=new ListNode(-1);
        ListNode* prev=head;
        
        ListNode* curr1=l1;
        ListNode* curr2=l2;
        
        while(curr1!=NULL && curr2!=NULL)
        {
            if(curr1->val<=curr2->val)
            {
                prev->next=curr1;
                prev=curr1;
                curr1=curr1->next;
            }
            else
            {
                prev->next=curr2;
                prev=curr2;
                curr2=curr2->next;
            }
        }
        
        if(curr1!=NULL)
        {
            prev->next=curr1;
        }
        if(curr2!=NULL)
        {
            prev->next=curr2;
        }
        
        return head->next;
    }
};
