import unittest
import logging
import copy

ASCI_TABLE_SIZE = 256


class Node:
    value = None
    next = None

    def __init__(self, v):
        self.value = v
        self.next = None


class LinkedList:
    head = None

    def __init__(self, lst=None):
        if isinstance(lst, list):
            self.list_to_linkedlist(lst)

    def __eq__(self, other):
        if not isinstance(other, LinkedList):
            # don't attempt to compare against unrelated types
            return False
        if self.length() != other.length():
            return False
        n = self.head
        m = other.head
        while n:
            if n.value != m.value:
                return False
            n = n.next
            m = m.next
        return True

    def length(self):
        n = self.head
        count = 0
        while n:
            count += 1
            n = n.next

    def add(self, v):
        new = Node(v)
        if not self.head:
            self.head = new
            return
        p = self.head
        while p.next:
            p = p.next
        p.next = new

    def list_to_linkedlist(self, lst):
        for item in lst:
            item = str(item)
            self.add(item)

    def print(self):
        p = self.head
        str_lst = ''
        if not p:
            print('[]')
        while p:
            str_lst += '{}->'.format(p.value)
            p = p.next
        print(str_lst)

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
        (LinkedList([2, 2, 2, 2, 2]), LinkedList([2])),
        (LinkedList([]), LinkedList([])),
        (LinkedList([1, 2, 3, 4, 5, 3]), LinkedList([1, 2, 3, 4, 5])),
        (LinkedList(['a', 1, 'a']), LinkedList(['a', 1])),
        (LinkedList(['b', 'b', 'a']), LinkedList(['b', 'a'])),
        (LinkedList([5, 6, 5, 6]), LinkedList([5, 6]))
    )

    def test_remove_dup(self):
        for lst, expected in self.test_cases:
            copy_lst_value = copy.deepcopy(lst)
            remove_dups2(lst)
            #logging.info("List: {}; Result: {}; Expected: {}".format(copy_lst_value, lst, expected))
            assert lst == expected


if __name__ == '__main__':
    logging.basicConfig(
        level=logging.INFO,
        format='%(levelname)s - %(message)s'
    )
    unittest.main()

    # # create a list
    # l = LinkedList()
    # #l.list_to_linkedlist(['a', 'b', 'c', 'b', 'd'])
    # l.list_to_linkedlist([1, 2, 1, 2, 3])
    # #l.list_to_linkedlist([2, 2, 2, 2, 2])
    # #l.list_to_linkedlist([])
    # l.print()
    # remove_dups(l)
    # l.print()



