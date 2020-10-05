class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> s;
        int ans=0,count=0;
        for(auto i:G){
            s.insert(i);
        }
        while(head){
            if(s.find(head->val)!=s.end()) count++;
            else{
                if(count) ans++;
                count=0;
            }
            head=head->next;
        }
        if(count) ans++;
        return ans;
    }
};