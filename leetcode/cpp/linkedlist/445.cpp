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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> l1Stack,l2Stack;
        ListNode *list=NULL;
        int x,y,carry=0;
        while(l1 || l2){
            if(l1){
                l1Stack.push(l1->val);
                l1=l1->next;
            }
            if(l2){
                l2Stack.push(l2->val);
                l2=l2->next;
            }
        }
        while(!l1Stack.empty() || !l2Stack.empty() || carry){
            x=0;
            y=0;
            if(!l1Stack.empty()){
                x=l1Stack.top();
                l1Stack.pop();
            }
            if(!l2Stack.empty()){
                y=l2Stack.top();
                l2Stack.pop();
            }
            x=x+y+carry;
            carry=(int)x/10;
            auto *temp=new ListNode(x%10);
            temp->next=list;
            list=temp;
        }
        return list;
    }
};