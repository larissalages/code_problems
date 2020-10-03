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
        if(!l1 && !l2) return l1;
        if(!l1 && l2) return l2;
        if(!l2 && l1) return l1;
        ListNode *mergedList,*head;
        int x,y;
        mergedList=new ListNode(0);
        head=mergedList;
        while(l1 || l2){
            x=l1? l1->val: INT_MAX;
            y=l2? l2->val: INT_MAX;
            if(l1 && x<=y){
                mergedList->next=new ListNode(x);
                l1=l1->next;
            }
            else if(l2){
                mergedList->next=new ListNode(y);
                l2=l2->next;
            }
            mergedList=mergedList->next;
        }
        return head->next;
    }
};