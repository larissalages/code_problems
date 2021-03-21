import unittest
import logging
from linked_list import *


# recursive solution
def kth_to_last(node, k):
    if node is None:
        return 0, None
    count, value = kth_to_last(node.next, k)
    count += 1
    if count == k:
        return count, node.value
    return count, value


# iterative solution
def kth_to_last_it(node, k):
    p1 = node
    p2 = node
    for i in range(k):
        if p2:
            p2 = p2.next
    while p2:
        p2 = p2.next
        p1 = p1.next

    return p1.value


class Test(unittest.TestCase):
    test_cases = (
        ([1], 1, 1),
        ([1, 2, 3, 4, 5, 6], 2, 5),
        ([1, 2], 1, 2),
        ([10, 20, 30, 40, 50], 5, 10)
    )

    def test_kth_to_last(self):
        for lst, k, expected in self.test_cases:
            lst = LinkedList(lst)
            _, value = kth_to_last(lst.head, k)
            assert value == expected

    def test_kth_to_last_it(self):
        for lst, k, expected in self.test_cases:
            lst = LinkedList(lst)
            value = kth_to_last_it(lst.head, k)
            assert value == expected


if __name__ == '__main__':
    logging.basicConfig(
        level=logging.INFO,
        format='%(levelname)s - %(message)s'
    )
    unittest.main()
