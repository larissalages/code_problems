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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *one=head,*two=head->next,*prev=NULL;
        head=head->next;
        while(one && two){
            one->next=two->next;
            two->next=one;
            if(prev) prev->next=two;
            prev=one;
            one=one->next;
            if(one) two=one->next;
        }
        return head;
    }
};