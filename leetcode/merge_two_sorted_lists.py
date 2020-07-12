# Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

# Example:

# Input: 1->2->4, 1->3->4
# Output: 1->1->2->3->4->4

#A very bad solution
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy_head_new_list = ListNode()
        p_new_list = dummy_head_new_list
        
        if l1 is None: return l2
        if l2 is None: return l1
        
        while l1 and l2:
            if l1.val < l2.val:
                new_node = ListNode(l1.val)
                p_new_list.next = new_node
                p_new_list = new_node
                l1 = l1.next
            else:
                new_node = ListNode(l2.val)
                p_new_list.next = new_node
                p_new_list = new_node
                l2 = l2.next               
        p_new_list.next= l1 or l2
        
        return dummy_head_new_list.next

        