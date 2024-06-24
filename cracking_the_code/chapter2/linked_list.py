class Node:
    value = None
    next = None

    def __init__(self, v):
        self.value = v
        self.next = None


class LinkedList:
    _head = None

    def __init__(self, lst=None):
        if isinstance(lst, list):
            self.list_to_linkedlist(lst)

    def __eq__(self, other):
        if not isinstance(other, LinkedList):
            # don't attempt to compare against unrelated types
            return False
        if self.length() != other.length():
            return False
        n = self._head
        m = other._head
        while n:
            if n.value != m.value:
                return False
            n = n.next
            m = m.next
        return True

    def length(self):
        n = self._head
        count = 0
        while n:
            count += 1
            n = n.next

    def add(self, v):
        new = Node(v)
        if not self._head:
            self._head = new
            return
        p = self._head
        while p.next:
            p = p.next
        p.next = new

    def list_to_linkedlist(self, lst):
        for item in lst:
            self.add(item)

    def print(self):
        p = self._head
        str_lst = ''
        if not p:
            print('[]')
        while p:
            str_lst += '{}->'.format(p.value)
            p = p.next
        print(str_lst)

    def head(self):
        return self._head