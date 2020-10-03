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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *l1;
        l1=new ListNode(0);
        auto l2=l1;
        while(head){
            if(head->next && head->val==head->next->val){
                while(head->next && head->val==head->next->val){
                    head=head->next;
                }
                head=head->next;
            }else{
                l1->next=head;
                l1=l1->next;
                head=head->next;
            }
        }
        l1->next=NULL;
        return l2->next;
    }
};