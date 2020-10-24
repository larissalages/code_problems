// Merged Two Sorted Linked Lists

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //If both the linked list are NULL than we simply return the NULL
        if(l1 == NULL && l2 == NULL)
            return NULL;
        
        //If one of the linked list is NULL than we return the other linked list
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        //We take mergedHead and mergedTail for our merged linked list of l1 and l2
        ListNode *mergedHead = NULL, *mergedTail = NULL;
        while(l1 != NULL && l2 != NULL)
        {
            //If l1's val is less than l2's val than l1's node should go first into the merged list
            if(l1->val < l2->val)
            {
                //We check if the merged list is still empty
                if(mergedHead == NULL)
                {
                    mergedHead = l1;
                    mergedTail = l1;
                }
                else
                {
                    mergedTail->next = l1;
                    mergedTail = mergedTail->next;
                }
                l1 = l1->next;
            }
            else
            {
                if(mergedHead == NULL)
                {
                    mergedHead = l2;
                    mergedTail = l2;
                }
                else
                {
                    mergedTail->next = l2;
                    mergedTail = mergedTail->next;
                }
                l2 = l2->next;
            }
        }
        
        //In case l1 and l2 are of different lengths than one of the list would get merged while the other would still have some nodes left. To merge the remaining nodes we have used the conditionals given below.
        if(l1 == NULL)
            mergedTail->next = l2;
        if(l2 == NULL)
            mergedTail->next = l1;
        
        //We return the merged linked list head.
        return mergedHead;
    }
};
