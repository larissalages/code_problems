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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!k || !head) return head;
        ListNode* temp,*resultList;
        int size=0;
        temp=head;
        while(temp!=NULL){
            size+=1;
            temp=temp->next;
        }
        temp=head;
        k%=size;
        if(!k) return head;
        size-=(k+1);
        while(size){
            temp=temp->next;
            size--;
        }
        resultList=temp->next;
        temp->next=NULL;
        temp=resultList;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head;
        return resultList;
    }
};