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
    ListNode* oh=nullptr;
    ListNode* ot=nullptr;
    
    ListNode* th=nullptr;
    ListNode* tt=nullptr;
    
    void addfirst(ListNode* node)
    {
        if(th==NULL)
        {
            th=node;
            tt=node;
        }
        else
        {
            node->next=th;
            th=node;
        }
    }
    
    int length(ListNode* head)
    {
        int l=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            l++;
            temp=temp->next;
        }
        
        return l;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0 || k==1 ) return head;
        
        int len=length(head);
        if(len<k) return head;
        
        ListNode* curr=head;
        while(curr!=NULL)
        {
            int tk=k;
            
            while(tk-->0)
            {
                ListNode* fwd=curr->next;
                curr->next=NULL;
                
                addfirst(curr);
                curr=fwd;
            }
            
            len-=k;
            
            if(ot==nullptr)
            {
                oh=th;
                ot=tt;
            }
            else
            {
                ot->next=th;
                ot=tt;
            }
            tt=nullptr;
            th=nullptr;
            
            if(len<k)
            {
                ot->next=curr;
                curr=nullptr;
            }
        }
        
        return oh;
    }
};
