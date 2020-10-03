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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *temp,*curr=head;
        int sum=0,cnt;
        while(curr){
            sum+=curr->val;
            if(sum==0){
                curr=curr->next;
                head=curr;
                continue;
            }
            temp=head;
            cnt=0;
            while(temp && temp!=curr){
                if(temp) cnt+=temp->val;
                if(cnt==sum){
                    temp->next=curr->next;
                    break;
                }
                if(temp) temp=temp->next;
            }
            curr=curr->next;
        }
        return head;
    }
};