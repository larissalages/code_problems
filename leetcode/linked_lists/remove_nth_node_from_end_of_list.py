
# Given a linked list, remove the n-th node from the end of list and return its head.

# Example:

# Given linked list: 1->2->3->4->5, and n = 2.

# After removing the second node from the end, the linked list becomes 1->2->3->5.
# Note:

# Given n will always be valid.

# Follow up:

# Could you do this in one pass?


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if head.next is None and n==1:
            return None
        dumb_node = ListNode(0, head)
        h = dumb_node
        head2 = h
        p = h
        for i in range(n):
            p = p.next
            
        while p is not None and p.next is not None:
            h = h.next
            p = p.next
            
        if h.next is not None:
            h.next = h.next.next
        return head2.next
