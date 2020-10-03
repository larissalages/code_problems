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
    ListNode* reversell(ListNode* head){
        ListNode* rev=NULL;
        while(head){
            auto *x=new ListNode(head->val);
            x->next=rev;
            rev=x;
            head=head->next;
        }
        return rev;
    }
    
    vector<int> nextLargerNodes(ListNode* head) {
        if(!head) return vector<int> (0);
        auto *rev=reversell(head);
        stack<int> s;
        vector<int> ans;
        if(s.empty()){
            ans.push_back(0);
            s.push(rev->val);
            rev=rev->next;
        }
        while(rev){
            while(rev && rev->val<s.top()){
                ans.push_back(s.top());
                s.push(rev->val);
                rev=rev->next;
            }
            while(rev && rev->val>=s.top()){
                s.pop();
                if(s.empty()){
                    ans.push_back(0);
                    s.push(rev->val);
                    rev=rev->next;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


//brute force approach
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        auto *p1=head,*p2=head;
        vector<int> v;
        while(p1){
            p2=p1->next;
            while(p2 && p2->val<=p1->val) p2=p2->next;
            if(!p2) v.push_back(0);
            else v.push_back(p2->val);
            p1=p1->next;
        }
        return v;
    }
};