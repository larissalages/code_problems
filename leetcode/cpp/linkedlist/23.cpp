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
   ListNode * mergeTwoLL(ListNode * head1 , ListNode * head2){
    if(head1 == nullptr || head2 == nullptr)
       return head1==nullptr?head2:head1;
    ListNode* curr1 = head1;
    ListNode* curr2 = head2;
    ListNode* head = new ListNode(-1);
    ListNode* curr = head;

    while(curr1!= nullptr && curr2!= nullptr){
        if(curr1->val <= curr2->val){
             curr->next = curr1;
             curr1 = curr1->next;
             curr = curr->next;
        }
        else{
            curr->next = curr2;
             curr2 = curr2->next;
             curr = curr->next;
        }
    }
    if(curr1==nullptr)
       curr->next = curr2;
    else if(curr2 == nullptr)
       curr->next = curr1;
    
    return head->next;
}
    ListNode* mergeKLL(vector<ListNode*> lists,int si ,int ei)
    {
        if(si==ei)
            return lists[si];
        if(si+1==ei)
            return mergeTwoLL(lists[si],lists[ei]);
        
        int mid=(si+ei)/2;
        return mergeTwoLL(mergeKLL(lists,si,mid),mergeKLL(lists,mid+1,ei));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        int si=0;int ei=lists.size()-1;
        
        return mergeKLL(lists,si,ei);
    }
};
