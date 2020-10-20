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
