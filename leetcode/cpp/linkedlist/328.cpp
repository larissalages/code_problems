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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *even=head->next,*odd=head,*temp;
        while(even){
            temp=odd->next;
            odd->next=even->next;
            if(!odd->next){
                odd->next=temp;
                return handler;
            }
            odd=odd->next;
            even->next=odd->next;
            odd->next=temp;
            even=even->next;
        }
        return head;
    }
};