import unittest
import logging
import copy
from linked_list import *

ASCI_TABLE_SIZE = 256


# First method (not that good)


def remove_dups(l):
    seen = []
    for i in range(ASCI_TABLE_SIZE):
        seen.append(False)
    p = l.head
    # Zero or one node
    if not p or (p and not p.next):
        return l
    while p:
        seen[ord(p.value)] = True
        if p.next:
            if seen[ord(p.next.value)] is True:
                p.next = p.next.next
                while p.next and p.value == p.next.value:
                    p.next = p.next.next
            else:
                seen[ord(p.next.value)] = True
        p = p.next


# Second method (better)


def remove_dups2(l):
    set_seen = set([])
    previous = None
    n = l.head

    while n:
        if n.value in set_seen:
            previous.next = n.next
        else:
            set_seen.add(n.value)
            previous = n
        n = n.next


class Test(unittest.TestCase):
    test_cases = (
        ([2, 2, 2, 2, 2], [2]),
        ([], []),
        ([1, 2, 3, 4, 5, 3], [1, 2, 3, 4, 5]),
        (['a', 1, 'a'], ['a', 1]),
        (['b', 'b', 'a'], ['b', 'a']),
        ([5, 6, 5, 6], [5, 6]),
        ([1, 1, 1, 1, 1, 1], [1])
    )

    def test_remove_dup(self):
        for lst, expected in self.test_cases:
            lst = LinkedList(lst)
            expected = LinkedList(expected)
            copy_lst_value = copy.deepcopy(lst)
            remove_dups2(lst)
            assert lst == expected


if __name__ == '__main__':
    logging.basicConfig(
        level=logging.INFO,
        format='%(levelname)s - %(message)s'
    )
    unittest.main()




