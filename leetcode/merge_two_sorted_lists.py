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
        p1 = l1
        p2 = l2
        dummy_head_new_list = ListNode()
        p_new_list = dummy_head_new_list
        
        if p1 is None:
            if p2 is None:
                return None
            else:
                return p2
        if p2 is None:
            return p1
        
        if p1.next is None and p2.next is None:
            if p1.val < p2.val:
                p1.next = p2
                return p1
            else:
                p2.next = p1
                return p2
        
        while p1 and p2:
            if p1.val < p2.val:
                new_node = ListNode(p1.val)
                p_new_list.next = new_node
                p_new_list = new_node
                p1 = p1.next
            else:
                new_node = ListNode(p2.val)
                p_new_list.next = new_node
                p_new_list = new_node
                p2 = p2.next
                
        while p1:
            new_node = ListNode(p1.val)
            p_new_list.next = new_node
            p_new_list = new_node
            p1 = p1.next
        
        while p2:
            new_node = ListNode(p2.val)
            p_new_list.next = new_node
            p_new_list = new_node
            p1 = p2.next
            
        return dummy_head_new_list.next
            
        