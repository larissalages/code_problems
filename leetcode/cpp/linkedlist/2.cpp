//Leetcode Problem #2 : Add Two Numbers
//Link to problem : https://leetcode.com/problems/add-two-numbers/
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
        ListNode * head = new ListNode(-1);   
        ListNode * tail = head;
        int carry = 0; //to calculate carry while adding digits
        while (l1 || l2 || carry) {
            int n1 = l1 ? l1->val : 0; //Adding zero doesn't change sum
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            l1 ? l1 = l1->next : NULL;
            l2 ? l2 = l2->next : NULL;
        }
        if (carry) 
            tail->next = new ListNode(1);
        
        return head->next;  
    }
};