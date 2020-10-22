//This Question can be solved both Iteratively as well as using Recursion
//Here, We have both the solutions. We have commented the Iterative Solution for now. We recommend you to go through both the solutions. 
//Once you complete the recursive solution comment it out and uncomment the iterative one and go through it!
  
  
  
  
/****************************************************Recursive Solution*****************************************************/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //Base Case
        if(head == NULL || head->next == NULL)
            return head;
        
        //Recursive Call on the LinkedList, We are working on the head ourseleves and letting recursion work on the rest Nodes.
        //Recursion would reverse and bring us the reverse linkedList from head onwards.
        
        ListNode* smallHead = reverseList(head->next);
        
        //We already have the end of the reverse linked list stored in head->next obtained
        
        head->next->next = head;
        head->next = NULL;
        
        //Putting the new head of reversed linked list into the head
        
        head = smallHead;
        
        return head;
    }
};





/***************************************************Iterative Solution*****************************************************/
/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *p=head,*q=NULL,*r=NULL; 
        while(p!=NULL)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        head=q;   
        return head;
    }
};
*/
