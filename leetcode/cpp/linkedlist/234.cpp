//simple O(n) solution,takes O(n) space
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* rev=NULL,*headref=head;
        int count=0;
        while(headref){
            ListNode* node=new ListNode(headref->val);
            node->next=rev;
            rev=node;
            headref=headref->next;
            count++;
        }
        count=count/2;
        while(count){
            if(head->val!=rev->val) return false;
            head=head->next;
            rev=rev->next;
            count--;
        }
        return true;
    }
};

//two pointer solution
class Solution{
public:
    ListNode* rev(ListNode* node){
        ListNode* revnode=NULL;
        while(node){
            auto *x=new ListNode(node->val);
            x->next=revnode;
            revnode=x;
            node=node->next;
        }
        return revnode;
    }

    bool isPalindrome(ListNode *head){
        auto *fast=head,*slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=head;
        slow=rev(slow);
        while(slow){
            if(fast->val!=slow->val) return false;
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }
};