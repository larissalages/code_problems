//method1
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int size=0;
        auto *headref=head;
        while(headref){
            headref=headref->next;
            size++;
        }
        size/=2;
        while(size){
            head=head->next;
            size--;
        }
        return head;
    }
};

//method2
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        auto *slow=head,*fast=head;
        while(true){
            if(!fast->next) return slow;
            if(!fast->next->next) return slow->next;
            slow=slow->next;
            fast=fast->next->next;
        }
    }
};