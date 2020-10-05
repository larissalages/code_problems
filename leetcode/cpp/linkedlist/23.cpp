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
    ListNode* merge_two(ListNode* l1,ListNode* l2){
        ListNode* res=NULL;
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val<=l2->val){
            res=l1;
            res->next=merge_two(l1->next,l2);
        }else{
            res=l2;
            res->next=merge_two(l1,l2->next);
        }
        return res;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       if(lists.empty()) return NULL;
       int last=lists.size()-1,i,j;
        while(last!=0){
            i=0;j=last;
            while(i<j){
                lists[i]=merge_two(lists[i],lists[j]);
                i++;
                j--;
            }
            last=j;
        }
        return lists[0];
    }
};