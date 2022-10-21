/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = 0, l2 = 0;
        ListNode *temp1 = headA, *temp2 = headB;
        while (headA != NULL) headA = headA->next, l1++;
        while (headB != NULL) headB = headB->next, l2++;
        int p = abs(l1 - l2);
        headA = temp1;
        headB = temp2;
        if (l1 > l2) {
            while (p > 0) headA = headA->next, p--;
        }
        else {
            while (p > 0) headB = headB->next, p--;
        }
        while (headA != NULL && headB != NULL) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};