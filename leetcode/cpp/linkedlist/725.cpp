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
    ListNode* getList(ListNode* head,int size){
        if(!size) return NULL;
        size-=1;
        ListNode* headref=head;
        while(size){
            headref=headref->next;
            size--;
        }
        head=headref->next;
        headref->next=NULL;
        return head;
    }
    
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int size=0;
        auto *head=root;
        vector<ListNode *> v;
        while(head){
            head=head->next;
            size+=1;
        }
        int rem=size%k,len=size/k;
        k-=rem;
        while(rem){
            auto *prev=root;
            root=getList(root,len+1);
            v.push_back(prev);
            rem--;
        }
        while(k){
            auto *prev=root;
            root=getList(root,len);
            v.push_back(prev);
            k--;
        }
        return v;
    }
};